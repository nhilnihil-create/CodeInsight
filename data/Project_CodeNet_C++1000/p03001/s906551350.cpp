#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 0;
ld w, h, x, y;

int main(){
	IOS
	cin >> w >> h >> x >> y;
	cout << setprecision(9) << fixed << w*h/2 << '\n';
	cout << ((x+x==w)&&(y+y==h)) << '\n';
}
