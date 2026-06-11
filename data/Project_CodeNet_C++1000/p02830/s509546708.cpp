#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 922337203685477;
const ll mininf = -922337203685477;
const ll nax = 1e5 + 5;
int n;

int main(){
	IOS
	cin >> n;
	int ta=0, tb=0;
	string a, b, c;
	cin >> a >> b;
	for(int i=0;i<2*n;i++){
		if(i&1){
			c+=b[tb];
			tb++;
		}
		else{
			c+=a[ta];
			ta++;
		}
	}
	cout << c << '\n';
}
