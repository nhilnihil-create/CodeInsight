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
      ll n,m; cin >> n >> m;
      vector<ll> a(n);
      rep(i,n) cin >> a[i];
      priority_queue<ll> q;
      rep(i,n) q.push(a[i]);
      while(m>0){
            auto x = q.top(); q.pop();
            x /= 2;
            q.push(x);
            m--;
      }
      ll ans = 0;
      while(!q.empty()){
            ans += q.top(); q.pop();
      }

      cout << ans << endl;

      return 0;
}
