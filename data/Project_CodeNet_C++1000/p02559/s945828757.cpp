#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Unionfind{
    vector<int> parent;
    void init(int forestSize){
        parent.resize(forestSize);
        for(int i=0;i<forestSize;i++){parent.at(i)=i;}
    }
    int root(int v){
        if(parent.at(v)==v){return v;}
        else{return parent.at(v)=root(parent.at(v));}
    }
    bool belong(int x,int y){
        if(root(x)==root(y)){return true;}
        else{return false;}
    }
    void unite(int x,int y){
        if(parent.at(x)!=parent.at(y)){parent.at(root(y))=root(x);}
    }
    /*
    Unionfind<int> rock;
    rock.init(N);
    */
};
template <typename T>
struct BIT{
    //区間加算O(log(N))
    //区間シグマ計算O(log(N))
    //単点加算O(log(N))
    //単点計算O(log(N))
    long long n;//元の数列のサイズ
    vector<T> bit[2];//データ収納用
    vector<T> for_bubblesort;
    void init(long long n_){
        n=n_+1;
        for(long long j=0;j<2;j++){
            bit[j].assign(n,0);
        }
    }
    void add_sub(long long p,long long i,T x){
        for(long long j=i;j<n;j+=j&-j){
            bit[p][j]+=x;
        }
    }
    void add(long long l,long long r,T x){//[l,r]に加算
        add_sub(0,l,-x*(l-1));
        add_sub(0,r+1,x*r);
        add_sub(1,l,x);
        add_sub(1,r+1,-x);
    }
    T sum_sub(long long p,long long i){
        T s(0);
        for (long long j=i;j>0;j-=j&-j){
            s+=bit[p][j];
        }
        return s;
    }
    T sum(long long i,long long j){//[i,j]のΣを計算
        return sum_sub(0,j)+sum_sub(1,j)*j-sum_sub(0,i-1)-sum_sub(1,i-1)*(i-1);
    }
    //ここから二分探索関連
    T binary_search_sum1(long long key){//a_1+a_2+...+a_x>=keyとなるような最小のxを求める(ただしa_i>=0)
    //key以上の値
            if(key<=0){
                return 0;
            }
            else{
                long long x=0,r=1;
                while(r<n){
                    r=r<<1;
                }
                for(long long length=r;length>0;length=length>>1){//長さlenは1段下るごとに半分に
                    if(x+length<n&&sum(x+1,x+length)<key){//採用するとき
                        key-=sum(x+1,x+length);
                        x+=length;
                    }
                }
                return x+1;
            }
    }
    T binary_search_sum2(long long key){//a_1+a_2+...+a_x<=keyとなるような最大のxを求める(ただしa_i>=0)
    //key以下の値
            key++;
            if(key<=0){
                return 0;
            }
            else{
                long long x=0,r=1;
                while(r<n){
                    r=r<<1;
                }
                for(long long length=r;length>0;length=length>>1){//長さlenは1段下るごとに半分に
                    if(x+length<n&&sum(x+1,x+length)<key){//採用するとき
                        key-=sum(x+1,x+length);
                        x+=length;
                    }
                }
                return x;
            }
    }
    //二分探索終わり
    //ここからはbubblesort関連
    void init_bubblesort(long long n_){
        n=n_+1;
        for_bubblesort.assign(n,0);
    }
    void add_bubblesort(long long i,T x) {
        for(long long j=i;j<n;j+=j&-j){
            for_bubblesort[j]+=x;
        }
    }
    T calculate_bubblesort(long long i) {
        T s=0;
        for(long long j=i;j>0;j-=j&-j){
            s+=for_bubblesort[j];
        }
        for(long long j=i-1;j>0;j-=j&-j){
            s-=for_bubblesort[j];
        }
        return s;
    }
    T bubblesort(){
        //bitとfor_bubblesort両方initしてadd_for_bubblesortしてから使う
        long long answer_for_bubblesort=0;
        long long sum_for_bubblesort;
        for(long long i=1;i<=n-1;i++){
            sum_for_bubblesort=calculate_bubblesort(i);
            answer_for_bubblesort+=i-sum(1,sum_for_bubblesort)-1;
            add(sum_for_bubblesort,sum_for_bubblesort,1);
        }
        return answer_for_bubblesort;
    }
    //bubblesort関連終わり
    /*
    使い方
    BIT<long long> rock;
    rock.init(N);    Nは加算などの操作を行う配列のサイズ
    ...(その後は適当に)
    */
};
int main(){
  #define int long long
  int N,Q;
  cin>>N>>Q;
  BIT<int> rock;
  rock.init(N);
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    rock.add(i+1,i+1,a);
  }
  for(int i=0;i<Q;i++){
    int x,y,z;
    cin>>x>>y>>z;
    if(x==0){
      rock.add(y+1,y+1,z);
    }
    else{
      cout<<rock.sum(y+1,z)<<endl;
    }
  }
}