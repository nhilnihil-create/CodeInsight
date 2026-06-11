#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define LOL cout<<'\n';
#define MOD 1000000007
#define sz(x) ((int)x.size())
#define INF LONG_LONG_MAX
#define NINF LONG_LONG_MIN
#define deb(x) cout << "[" << #x << "=" << x << "]" << '\n';
#define deb2(x,y) cout << "[" << #x << "=" << x << "] [" << #y << "=" << y << "]" << '\n';
#define deb3(x,y,z) cout << "[" << #x << "=" << x << "] [" << #y << "=" << y << "] [" << #z << "=" << z << "]" << '\n';

const int N=2e5+7;

void solve(){
	int n; cin>>n;
	int a[n];
	vector<int> v(n+1,0);
	for(int i=0 ; i<n ; i++) cin>>a[i],++v[a[i]];
	vector<int> lol(n+1,0);
    //for(int i=1 ; i<=n ; i++) cout<<v[i]<<' ';LOL
	int cnt=0;
        for(int i=1 ; i<=n ; i++){
		if(v[i]>=2) cnt+=max(0LL,((v[i]-1)*(v[i]))/2);
	}
    
    //for(int i=1 ; i<=n ; i++) cout<<v[i]<<' ';LOL
	
    
    for(int i=0 ; i<n ; i++){
		cout<<cnt-v[a[i]]+1;LOL
	}
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int _=1; //cin>>_;
  while(_--) solve();
  return 0;
}