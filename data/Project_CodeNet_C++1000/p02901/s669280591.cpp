#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7,INF=mod*mod*3;//M_PI
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll N,M;
ll dp[1005][9000];
ll a[1005];
ll b[1005];
ll c[1005][15];

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N>>M;
rep(i,M){
    cin>>a[i]>>b[i];
    rep(j,b[i]){
        cin>>c[i][j];
        c[i][j]--;
    }
}
rep(i,1005) rep(j,4100) dp[i][j]=INF;
dp[0][0]=0;
ll sn=0;
rep(k,15){
    rep(i,b[0]){
        if(k==c[0][i]) sn+=(1<<k);
    }
}
dp[0][sn]=a[0];
rep1(m,M){
    rep(i,4100){
        ll ii=i;
        string s="000000000000000"; 
        ll st=0;
        while(ii){
            if(ii%2) s[st]='1';
            ii/=2; 
            st++;
        }
        rep(k,b[m]){
            s[c[m][k]]='1';
        }
        ll nm=0;
        rep(k,N){
            if(s[k]=='1') nm+=(1<<k);
        }
        dp[m][nm]=min(dp[m][nm],dp[m-1][i]+a[m]);
        dp[m][i]=min(dp[m][i],dp[m-1][i]);
    }
}
ll nmax=0;
rep(i,N) nmax+=(1<<i);
cout<<(dp[M-1][nmax]==INF?-1:dp[M-1][nmax])<<endl;



}
    
