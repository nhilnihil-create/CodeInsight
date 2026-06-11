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
	vector<int> a(n),b(n);
	for(int i=0 ; i<n ; i++){
		cin>>a[i]>>b[i];
	}
	sort(all(a)); sort(all(b));
	int ans=0;
	if(n&1){
		ans=abs(b[sz(b)/2]-a[sz(a)/2])+1;
	}
	else{
		int just=0;
		ld x=(b[sz(b)/2-1]+b[sz(b)/2])/2.0;
		if(x==(int)x){
		}
		else{
			just++;
		}
		ans=x;
		x=(a[sz(a)/2-1]+a[sz(a)/2])/2.0;
		if(x==(int)x){
			just++;
		}
		ans=abs(ans-(int)x)*2;
		ans+=just;
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
