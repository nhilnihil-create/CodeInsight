#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


const ll N=100001;

int dp[667][2010];

const ll mod=1000000000+7;




int main(){

    int S;
    cin>>S;

    int p=S/3;

    for(int i=3;i<=S;++i){
        dp[1][i]=1;
        
    }
/*
    for(int i=0;i<=p;i++){
        for(int j=0;j<=S;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    for(int i=1;i<=p;i++){
        for(int j=3*i;j<=S;++j){
           for(int k=3;k<=S-j;++k){
               dp[i+1][j+k]=(dp[i+1][j+k]+dp[i][j])%mod;
           }
    
        }
        /*
        
        cout<<"========="<<endl;
         for(int i=0;i<=p;i++){
        for(int j=0;j<=S;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
        
    }
    */
    
    }

    ll ans=0;

    for(int i=1;i<=p;i++){

        ans=(ans+dp[i][S])%mod;
    }


cout<<ans<<endl;
    
}

