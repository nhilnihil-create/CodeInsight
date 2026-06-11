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
long double n, ans=0.0;

int main(){
	IOS
	cin >> n;
	for(int i=0;i<n;i++){
		long double a;
		cin >> a;
		ans+=(1/a);
	}
	cout << setprecision(9) << fixed;
	cout << 1/ans << '\n';
} 
