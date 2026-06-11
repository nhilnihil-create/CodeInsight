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
int n,m,k,q,l,r,x,y,z;
int a[N],b[N],c[N];
string s,t;
int ans=0,cnt=0,f=0;

void solve(){
	cin>>n;
	for(int i=0 ; i<n ; i++) cin>>a[i];
	for(int i=0 ; i<n ; i++){
		if(a[i]==0) f=1;
	}
	if(f){
		cout<<0;LOL
		return;
	}
	ld d=0;
	for(int i=0 ; i<n ; i++){
		d+=log10(a[i]);
	}
	if(d>18){
		cout<<-1;LOL
		return;
	}
	cnt=1;
	ans=1000000000000000000;
	for(int i=0 ; i<n ; i++){
		cnt*=a[i];
		if(cnt>ans){
			cout<<-1;LOL
			return;
		}
	}
	if(cnt>ans){
		cout<<-1;LOL
		return;
	}
	else{
		cout<<cnt;LOL
	}
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cout<<setprecision(2);
  int _=1; //cin>>_;
  for(int i=1 ; i<=_ ; i++) solve();
  return 0;
}
