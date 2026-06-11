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
string u, s, t;
int a, b;

int main(){
	IOS
	int c, d;
	cin >> s >> t >> a >> b >> u;
	c=a, d=b;
	if(u==s){
		c--;
	}
	if(u==t){
		d--;
	}
	cout << c << ' ' << d << '\n';
}