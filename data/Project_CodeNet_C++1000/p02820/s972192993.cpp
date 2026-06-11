#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define fi first
#define se second
#define pf push_front
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define debug(val) cerr << "Value " << #val << " : " << val << '\n';
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ld epsilon = 10e-9;
const ll nax = 1e5+5;
ll n, k, r, s, p, arr[nax], ans=0;
string a;
unordered_map<ll, bool>skip;
	
int main(void){
	IOS
	cin >> n >> k;
	cin >> r >> s >> p;
	cin >> a;
	ll l=a.length();
	for(int i=0;i<l;i++){
		skip[i]=0;
	}
	for(int i=0;i+k<l;i++){
		if(skip[i]) continue;
		if(a[i]==a[i+k]){
			skip[i+k]=1;
		}
	}
	for(int i=0;i<l;i++){
		if(skip[i]) continue;
		else{
			if(a[i]=='r') ans+=p;
			else if(a[i]=='s') ans+=r;
			else ans+=s;
		}
	}
	cout << ans << '\n';
}
