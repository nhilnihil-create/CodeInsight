#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(),c.end()
#define init(c) memset(c,0,sizeof c)
#define S second
#define F first
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
const int N=20000005;
int n,k,x,t,a,m;
string s;
vi v;

void solve(){
	cin >> n >>s;
	vi b(n+10,0),r(n+10,0),g(n+10,0);	
 	for(int i =n-1;i>=0;i--){
 		r[i]=r[i+1];
 		g[i]=g[i+1];
 		b[i]=b[i+1];
 		if(s[i]=='R'){
 			r[i]++;
 		}else if(s[i]=='G'){
 			g[i]++;
 		}else{
 			b[i]++;
 		}
 	}
 	 			set<char>st;

 	ll ans = 0;
 	for(int i =0;i<n;i++){
 		if(s[i] == 'R'){
 			ans= (ans+1ll*g[i]*b[i]);
 		}else if(s[i]=='G'){
			ans= (ans+1ll*r[i]*b[i]);
 		}else{
 			ans= (ans+1ll*g[i]*r[i]);
 		}
 		for(int j=1;j<n;j++){
 			st.clear();

 			for(int e=i;e<n&&e<=i+j*2;e+=j){
 				st.insert(s[e]);
 			}

 			if(st.size()==3){
  				ans--;
 			}
 		}

 	}
 	cout << ans;
}
 
int main(){

	t=1;
	while(t--){
		solve();
	}
	
	return 0;
}