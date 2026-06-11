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
string a;
int b;

int main(){
	IOS
	cin >> a;
	b=a.length();
	int l=0;
	int r=b-1;
	int ans=0;
	while(l<=r){
		if(a[l]!=a[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout << ans << '\n';
}
