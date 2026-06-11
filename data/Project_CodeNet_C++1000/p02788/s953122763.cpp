#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD=1e9+7;
const long double Pi=acos(-1);
using  P=pair<ll,ll>;
ll gcd(ll a,ll b){//aとbの最大公約数を返す//計算量は0(log(max(a,b))
  if(a%b==0){return b;}
  else{return gcd(b,a%b);}
}
ll lcm(ll a,ll b){//aとbの最小公倍数を返す//計算量は0(log(max(a,b))
  return a*b/gcd(a,b);
}
ll pow(ll x,ll y){//x^yを返す//計算量は0(log(y))
  ll tmp=x,res=1;
  while(y){
    if(y%2){res=res*tmp%MOD;}
    y>>=1;
    tmp=tmp*tmp%MOD;
  }
  return res;
}
ll nature(ll a){//絶対値を返す
  if(a>=0){return(a);}
  else{return(-1*a);}
}
ll prime(ll a){//素数なら1を返す//計算量は0(sqrt(a))
  if(a==2){return 1;}
  else if(a%2==0 || a==1){return 0;}
  for(ll i=3;i*i<=a;i+=2){if(a%i==0){return 0;}}
  return 1;
}
vector<int> Z;
void z_algorithm(string str){//計算量はO(str.size())
  Z.resize(str.size());
  Z.at(0)=str.size();
  int m=1,n=0;
  while(m<(int)str.size()){
    while(m+n<(int)str.size()&&str.at(n)==str.at(m+n)){n++;}
    Z.at(m)=n;
    if(n==0){
      m++;
      continue;
    }
    int k=1;
    while(k+Z.at(k)<n){
      Z.at(m+k)=Z.at(k);
      k++;
    }
    m+=k;
    n-=k;
  }
}
template <typename T>
struct BIT{
    //区間加算O(log(N))
    //区間シグマ計算O(log(N))
    //単点加算O(log(N))
    //単点計算O(log(N))
    int n;//元の数列のサイズ
    vector<T> bit[2];//データ収納用
    void init(int n_){
        n=n_+1;
        for(int j=0;j<2;j++){
          bit[j].assign(n,0);
        }
    }
    void add_sub(int p,int i,T x){
        for(int j=i;j<n;j+=j&-j){
            bit[p][j]+=x;
        }
    }
    void add(int l,int r,T x){//[l,r]に加算
        add_sub(0,l,-x*(l-1));
        add_sub(0,r+1,x*r);
        add_sub(1,l,x);
        add_sub(1,r+1,-x);
    }
    T sum_sub(int p,int i){
        T s(0);
        for (int j=i;j>0;j-=j&-j){
            s+=bit[p][j];
        }
        return s;
    }
    T sum(int i,int j){//[i,j]のΣを計算
        return sum_sub(0,j)+sum_sub(1,j)*j-sum_sub(0,i-1)-sum_sub(1,i-1)*(i-1);
    }
    T binary_search(int key){// a_1 + a_2 + ... + a_x >= w となるような最小の x を求める(ただし a_i >= 0)
            if(key<=0){
                return 0;
            }
            else{
                int x=0,r=1;
                while(r<n){
                    r=r<<1;
                }
                for(int length=r;length>0;length=length>>1){//長さlenは1段下るごとに半分に
                    if(x+length<n&&bit[x+length]<key){//採用するとき
                        key-=bit[x+length];
                        x+=length;
                    }
                }
                return x+1;
            }
    }
    /*
    使い方
    BIT<int> rock;
    rock.init(N);    Nは加算などの操作を行う配列のサイズ
    ...(その後は適当に)
    */
};
int main(){
    long long N,D,A;
    cin>>N>>D>>A;
    vector<P> vec(0);
    vector<long long> len(N-1);
    for(long long i=0;i<N;i++){
        long long a,b;
        cin>>a>>b;
        long long hp=b/A;
        if(b%A!=0){hp++;}
        vec.push_back(make_pair(a,hp));
    }
    sort(vec.begin(),vec.end());
    for(long long i=0;i<N-1;i++){
        long long key=vec.at(i).first+2*D;
        long long left=0,right=N-1,ans=0;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(vec.at(mid).first<=key){
                left=mid+1;
                ans=max(ans,mid);
            }
            else{
                right=mid-1;
            }
        }
        len.at(i)=min(ans+1,N);
        //cout<<i<<" "<<len.at(i)<<endl;
    }
    BIT<int> rock;
    rock.init(N);
    for(long long i=1;i<=N;i++){
        rock.add(i,i,vec.at(i-1).second);
    }
    long long answer=0;
    for(long long i=1;i<=N-1;i++){
        if(rock.sum(i,i)<=0){
            continue;
        }
        else{
            long long damage=rock.sum(i,i);
            answer+=damage;
            rock.add(i,len.at(i-1),-1*damage);
        }
    }
    if(rock.sum(N,N)>0){
        answer+=rock.sum(N,N);
    }
    cout<<answer<<endl;
}