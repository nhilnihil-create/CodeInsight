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

int main(){
	IOS
	int x, n, sums=0;
	cin >> x >> n;
	while(n--){
		int a;
		cin >> a;
		sums+=a;
	}
	if(sums>=x){
		cout << "Yes" << '\n';
	}
	else{
		cout << "No" << '\n';
	}
}

