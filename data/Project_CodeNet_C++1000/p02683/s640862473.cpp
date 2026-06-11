#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using ll= long long;
using namespace std;

int main(){
    int N,M,X;
    cin>>N>>M>>X;
    
    int C[N],A[N][M];
    rep(i,N){
        cin>>C[i];
        rep(j,M){
            cin>>A[i][j];
        }
    }
    int ans=100000000;
    rep(bit,(1<<N)){
        int Csum=0;
        vector<int> Asum(M,0);
        bool ok=true;
        rep(j,N){
            if((bit>>j)&1){
                Csum+=C[j];
                rep(k,M){
                    Asum[k]+=A[j][k];
                }
            }
        }
        rep(i,M){
            if(Asum[i]<X){
                ok=false;
                break;
            }
        }
        if(ok==true){
            ans=min(ans,Csum);
        }
    }
    if(ans==100000000){
        ans=-1;
    }

    cout<<ans<<endl;
    }
    
    
    
    
    
  
 
 


