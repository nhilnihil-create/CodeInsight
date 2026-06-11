#include <bits/stdc++.h>
using namespace std;
#define all(arr) arr.begin(), arr.end() 
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
string s, ans;

int main(){
	IOS
	cin >> n >> s;
	for(int i=0;i<n;i++){
		if(s[i]!=s[i-1]){
			ans+=s[i];
		}
	}
	cout << ans.length() << '\n';
}
