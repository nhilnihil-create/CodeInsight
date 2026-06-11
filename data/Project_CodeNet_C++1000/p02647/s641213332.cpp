#include <iostream>

#define rep(i,n) for(int i=0;i!=(n);++i)

using namespace std;

typedef long long ll;


int main(){
    int N,K;
    scanf("%d %d",&N,&K);

    ll A[N],B[N];
    rep(i,N) scanf("%lld",A+i);
    rep(i,N) B[i]=0;

    int a,b,c;

    rep(ki,K){
        rep(i,N){
            a=i-A[i]>=0?i-A[i]:0;
            b=i+A[i]+1<=N?i+A[i]+1:N;
            B[a]+=1;
            if(b<N){B[b]-=1;}
        }
        /*rep(i,N)cout<<B[i]<<" ";
        cout<<endl;*/
        for(int i=0;i!=N-1;++i){
            B[i+1]=B[i]+B[i+1];
        }
       /* rep(i,N)cout<<B[i]<<" ";
        cout<<endl;*/
        bool flag=true;
        for(int i=0;i!=N;++i){
            if(A[i]!=B[i]){
                flag=false;
            }
            A[i]=B[i];
            B[i]=0;
            
        }
        if(flag){
            break;
        }
        
    }

    rep(i,N){
        cout<<A[i]<<" ";
    }
    cout<<endl;

}