
/*     If they say
    Who cares if one more light goes out?
    In a sky of a million stars
    It flickers, flickers
    Who cares when someone's time runs out?
    If a moment is all we are
    We're quicker, quicker
    Who cares if one more light goes out?
    Well I do
*/

#include "bits/stdc++.h"
using namespace std;

#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) ((a) / gcd(a,b)) * (b)
#define all(x)  x.begin(),x.end()

#define ll long long
#define ull unsigned long long
#define VI vector<int>
#define VLL vector<ll>
#define VS vector<string>
#define MPII map<int, int>
#define SET set<int>
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define MEM(a, b) memset(a, (b), sizeof(a))
#define fast_io   ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);

ll MOD = 1e9+7;

ll add(ll a, ll b){a+=b; a%=MOD;if(a<0) a+=MOD;return a;}
//doesn't work for neg numbers

ll mult(ll a, ll b){if(a>MOD) a%=MOD;if(b>MOD) b%=MOD;ll ans=(a*b)%MOD;if(ans<0) ans+=MOD;return ans;}
//doesn't work for neg numbers

ll pw(ull a, ull b){ll r=1;while(b){if(b&1) r=mult(r,a);a=mult(a,a);b>>=1;}return r;}
//doesn't work for neg numbers

void solve(){
	string s;
	cin>>s;
	int n, flg=0, a=0,b=0;
	cin>>n;
	char c;
	string tmp="";
	while(n--){
		cin>>a;
		if(a==1){
			flg++;
			continue;
		}
		cin>>b>>c;
		if(b==1){
			if(flg%2!=0){
				s+=c;
			}
			else{
				tmp=s;
				s=c+tmp;
			}
		}
		else{
			if(flg%2==0){
				s+=c;
			}
			else{
				tmp=s;
				s=c+tmp;
			}
		}
		//cout<<s<<endl;
	}
	if(flg%2!=0){
        for(int i = s.length()-1 ; i >= 0 ; i--)cout<<s[i];
        cout<<endl;
	}
	else cout<<s<<endl;
}

int main(){
// 	#ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif
    fast_io;
    ll t, k=0;
    t=1;
    while(t--){
        //k++;
        //cout<<"Case "<<k<<": ";
        solve();
    }
}
