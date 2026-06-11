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
int n, m;

int main(){
	IOS
	cin >> n >> m;
	int nugas=0;
	while(m--){
		int a;
		cin >> a;
		nugas+=a;
	}
	if(nugas>n){
		cout << -1 << '\n'; return 0;
	}
	if(nugas==n){
		cout << 0 << '\n'; return 0;
	}
	cout << n-nugas << '\n';
}