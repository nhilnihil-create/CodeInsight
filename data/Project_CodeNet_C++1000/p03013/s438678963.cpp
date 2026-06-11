#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    int n,m;
    cin>>n>>m;
    vector<bool> a(n+2,true);
    vector<ll> dp(n+1);
    for(int i=1;i<=m;i++){
        int b;
        cin>>b;
        a[b]=false;
    }

    dp[0]=1;
    for(int i=0;i<=n;i++){
        if(a[i]){
            for(int j=1;j<=2&&i+j<=n;j++){
                if(a[i+j]){
                    dp[i+j]+=dp[i];
                    dp[i+j]%=1000000007;
                }
            }
        }
    }
    cout<<dp[n]<<endl;
}