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
string s;

int main(){
	IOS
	ll ans=0;
	cin >> n >> s;
	for(int i=0;i+2<n;i++){
		if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C'){
			ans++;
		}
	}
	cout << ans << '\n';
}
