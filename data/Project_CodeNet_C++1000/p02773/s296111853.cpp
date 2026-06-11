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
#define deb(x) cout << "[" << #x << "=" << x << "]" << '\n'
#define deb2(x,y) cout << "[" << #x << "=" << x << "] [" << #y << "=" << y << "]" << '\n'
#define deb3(x,y,z) cout << "[" << #x << "=" << x << "] [" << #y << "=" << y << "] [" << #z << "=" << z << "]" << '\n'

void solve(){
	int n; cin>>n;
	string s;
	map<string,int> m;
	for(int i=0 ; i<n ; i++){
		cin>>s;
		m[s]++;
	}
	int ma=0;
	for(auto x:m){
		ma=max(ma,x.s);
	}
	for(auto x:m){
		if(x.s==ma){
			cout<<x.f;LOL
		}
	}
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  //int _;
  //for(cin>>_ ; _ ; --_){
    //cout<<"Case "<<_<<": ";
    solve();
  //}
  return 0;
}