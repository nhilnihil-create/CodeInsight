#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 0;
ll negasi=0, a, b, c, d, ans=0;
	
int main(){
	IOS
	cin >> a >> b >> c >> d;
	ll kpk=(c*d)/__gcd(c, d);
	ans=abs(a-b)+1;
	negasi=(b/c-(a-1)/c)+(b/d-(a-1)/d)-(b/kpk-(a-1)/kpk);
	cout << ans-negasi << '\n';
}
