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
#define deb(x) cout << "[" << (#x) << "=" << x << "]" << '\n';
#define deb2(x,y) cout << "[" << (#x) << "=" << x << "] [" << (#y) << "=" << y << "]" << '\n';
#define deb3(x,y,z) cout << "[" << (#x) << "=" << x << "] [" << (#y) << "=" << y << "] [" << (#z) << "=" << z << "]" << '\n';

const int N=1e5+7;

void solve(){
	int n; cin>>n;
	vector<pair<int,int>> v;
	int cnt=0;
	while(n%2==0){
		cnt++;
		n/=2;
	}
	if(cnt>0) v.pb({2,cnt});
	for(int i=3 ; i*i<=n ; i+=2){
		cnt=0;
		while(n%i==0){
			cnt++;
			n/=i;
		}
		if(cnt>0) v.pb({i,cnt});
	}
	if(n>1){
		int f=0;
		for(int i=0 ; i<sz(v) ; i++){
			if(v[i].f==n){
				v[i].s++;
				f=1;
				break;
			}
		}
		if(f==0) v.pb({n,1});
	}
	int ans=0;
	for(int i=0 ; i<sz(v) ; i++){
		int x=sqrt(1+8*v[i].s);
		x--;
		x/=2;
		ans+=x;
	}
	cout<<ans;LOL
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cout<<setprecision(2);
  int _=1; //cin>>_;
  for(int i=1 ; i<=_ ; i++) solve();
  return 0;
}
