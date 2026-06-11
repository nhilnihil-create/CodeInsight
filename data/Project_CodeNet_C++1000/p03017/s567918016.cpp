#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long int ll;
#define int long long int
typedef vector<ll> vi;
typedef pair<int, int> ii; typedef vector<ii> vii;
#define INF numeric_limits<ll>::max()
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
ll powmod(ll a,ll l, ll md){ll res=1;while(l){if(l&1)res=res*a%md;l/=2;a=a*a%md;}return res;}
ll binpow(ll a,ll l){ll res=1;while(l){if(l&1)res=res*a;l/=2;a=a*a;}return res;}
ll invmod(ll a, ll md){return powmod(a,md-2,md);}
const ll inf = 0xFFFFFFFFFFFFFFFL;


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll n, a, b, c, d;
	cin>>n>>a>>b>>c>>d;
	string s;
	cin>>s;
	a--;b--;c--;d--;
	bool flag = true;
	if ((a<b && b<c && c<d)|| (a<c && c<b && b<d)){
		for (ll i = a+1 ; i<c;i++){
			if (s[i] == '#' && s[i+1]=='#'){
				flag = false;
				break;
			}

		}
		for (ll i = b+1 ; i<d;i++){
			if (s[i] == '#' && s[i+1]=='#'){
				flag = false;
				break;
			}

		}

	}
	else{
		for (ll i = a+1 ; i<c;i++){
			if (s[i] == '#' && s[i+1]=='#'){
				flag = false;
				break;
			}

		}
		if (flag){
			bool flag1 = false;
			for (ll i = b ; i<=d;i++){
				if (s[i-1] == '.' && s[i+1]=='.'&& s[i]== '.'){
					flag1 = true;
					break;
				}
			}
			if (flag1==false)flag = false;

		}


	}
	if (flag)cout<<"Yes"<<"\n";
	else cout<<"No"<<"\n";
    return 0;
}
 