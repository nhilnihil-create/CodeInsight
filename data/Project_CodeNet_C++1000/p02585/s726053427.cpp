#include <bits/stdc++.h>
using namespace std;
const long long INF = 2*1e18;

//累積和は関数化しておくと脳へのダメージが少ない
vector<long long> A,Al,Ar;
//regist:累積和に使うvectorを登録する
void regist(vector<long long> D){
    A=D;
    Al=D;
    for(long long i=0;i<((long long)D.size())-1;i++){
        Al[i+1]=Al[i]+D[i+1];
    }
    Ar=D;
    for(long long i=((long long)D.size())-2;i>=0;i--){
        Ar[i]=Ar[i+1]+D[i];
    }
}

//accu:l,l+1,...,rの総和(modを貫通してl>rでも総和にする、
//l=rだとA[l]を返しl=r+1だと全体の和になる)
long long accu(long long l,long long r){
    if(l<=r){
        if(l==0){
            return Al[r];
        }else{
            return Al[r]-Al[l-1];
        }
    }else{
        return Al[r]+Ar[l];
    }
}

//sum:そのまんま総和
long long sum(void){
    return Ar[0];
}
//累積和ここまで


signed main(void){
    
    long long N,K,a;
    vector<long long> P,C;
    
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> a;
        a--;
        P.push_back(a);
    }
    for(int i=0;i<N;i++){
        cin >> a;
        C.push_back(a);
    }
    
    //まずはループごとに分解する
    //visited:過去にそれを含むループが調べられているか
    vector<bool> visited(N,false);
    long long Ans = -INF;
    
    for(int i=0;i<N;i++){
        if(visited[i])continue;
        long long k = i;
        vector<long long> now={};
        while(1){
            if(visited[k])break;
            visited[k]=true;
            now.push_back(C[k]);
            k = P[k];
        }
        //これでnowはiを含むループ全体になった
        
        //念の為空のときは避けておく
        //多分使われてないと思うけどね　ゼロ割り怖すぎる
        if(now.size()==0)continue;
        regist(now);
        
        long long S = sum();
        
        if(S<=0){
            //ループ総和が負のときは1~min(K,L)の中に最大がある
            long long num=-INF;
            long long L = now.size();
            for(long long i=0;i<L;i++){
                for(long long j=0;j<L;j++){
                    long long s;
                    if(i<=j){
                        s = j-i+1;
                    }else{
                        s = L-(i-j-1);
                    }
                    //sは区間に含まれる要素の数
                    if(s<=K){
                        num = max(num,accu(i,j));
                        //accuはi~jまでの和
                    }
                }
            }
            Ans = max(Ans,num);
            
        }else{
            //ループ総和が正のときはK-L+1~Kに総和がある
            //負のときと実装が若干違う　どちらでもよし
            long long num = -INF;
            long long L = now.size();
            for(long long i=0;i<L;i++){
                for(long long s=max(1ll,K-L+1);s<=K;s++){
                    long long temp = accu(i,(i+s-1)%L);
                    temp += S*((s-1)/L);
                    //tempはi,i+1,...,i+s-1の和
                    num = max(num,temp);
                }
            }
            Ans = max(Ans,num);
        }
        
    }
    cout << Ans << endl;
    
    return 0;
}
