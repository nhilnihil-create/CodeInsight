#include<bits/stdc++.h>
#define rep(i,a) for(int (i)=0; (i)<(a); (i)++)
#define rep2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define MOD 1000000007
#define all(v) v.begin(), v.end()
#define m0(x) memset(x,0,sizeof(x))
#define chmax(a,b) if(b>a) a = b
#define chmin(a,b) if(b<a) a = b
#define LINF 1e9+10
typedef long long ll;

using namespace std;

int dx[] = {1,-1, 0, 0};
int dy[] = {0, 0,-1, 1};
ll dp[1050][6000]; 

int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      ll n,m,tmp; cin >> n >> m;
      vector<ll> a(m+1), b(m+1);
      vector<vector<ll>> c(m+1);
      map<ll,ll> mp;
      rep2(i,1,m+1){
            cin >> a[i] >> b[i];
            rep(j,b[i]){ cin >> tmp; mp[tmp]++; c[i].push_back(tmp);}
      }
      if(mp.size() != n){ cout << "-1" << endl; return 0;}
      
      rep(i,1050)rep(j,6000) dp[i][j] = LINF;
      
      dp[0][0] = 0;

      rep(i,m+1)for(int bit = 0; bit < (1<<n); bit++){
            int bit2 = bit;
            for(auto key: c[i]) if( (bit >> (key-1)) & 1) bit2 -= pow(2,key-1);
            if(i-1 >= 0) dp[i][bit] = min(dp[i-1][bit], dp[i-1][bit2] + a[i]);
      }
      cout << dp[m][ (1 << n) - 1] << endl;


      return 0;
}
