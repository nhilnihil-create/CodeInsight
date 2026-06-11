#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
typedef long long ll;
typedef pair<int,int> pii;


ll sum[2005][2005];
const ll MOD = 1e9+7;
int main(){
    int n,m;
    cin>>n>>m;
    vector<ll>s(n+1,0);
    vector<ll>t(m+1,0);
    rep(i,n){
        cin>>s[i+1];
    }
    rep(i,m){
        cin>>t[i+1];
    }
    rep(i,2005) sum[0][i]=1;
    rep(i,2005) sum[i][0]=1;
    REP(i,n){
        REP(j,m){
            if(s[i]==t[j]){
                sum[i][j]=(sum[i-1][j]+sum[i][j-1])%MOD;
            }
            else{
                sum[i][j]=(0-sum[i-1][j-1]+sum[i-1][j]+sum[i][j-1]+MOD)%MOD;

            }
        }
    }
    cout<<sum[n][m]<<endl;
    return 0;
}