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
int n;

int main(){
	IOS
	cin >> n;
	vector<int>a(n+5), b(n+5), c(n+5);
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		cin >> b[i];
	}
	for(int i=1;i<n;i++){
		cin >> c[i];
	}
	ll sums=0;
	for(int i=1;i<=n;i++){
		sums+=b[a[i]];
		if(i!=1&&a[i]==a[i-1]+1){
			sums+=c[a[i-1]];
		}
	}
	cout << sums << '\n';
}
