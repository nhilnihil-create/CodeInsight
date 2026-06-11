#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long
#define FAST {ios_base::sync_with_stdio(false);cin.tie(NULL);}
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define rep(n) for(int i=0;i<(n);i++)
#define rrep(n) for(int i=(n)-1;i>=0;i--)
#define mem(a,b) memset((a),(b),sizeof (a))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define INF (long long) 1e18
#define MOD 1000000007


void solve(){
      int n;
      cin>>n;
      map<string,int> m;
      for(int i=0;i<n;i++){
            string s;
            cin>>s;
            sort(all(s));
            m[s]++;
      }
      int ans = 0;
      for(auto x = m.begin();x!=m.end();x++){
            //cout<<(*x).ff<<" ";
            int num = (*x).ss;
            ans += num*(num-1)/2;
            
      }
      cout<<ans<<endl;
}

int32_t main(){
      FAST
      int t=1;
      //cin>>t;
      while(t--)
            solve();
      return 0;
}


