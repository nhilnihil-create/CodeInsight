#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie();cout.tie();
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 9223372036854775807;
const ll mininf = -9223372036854775807;
const ll nax = 0;
ll n, a, b;

int main(){
	IOS
	cin >> n >> a >> b;
	ll A=n/(a+b);
	ll B=n%(a+b);
	cout << a*A+min(a, B) << '\n';
}