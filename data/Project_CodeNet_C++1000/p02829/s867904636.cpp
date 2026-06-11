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
bool vis[4];

int main(){
	IOS
	int a, b;
	cin >> a >> b;
	vis[a]=1, vis[b]=1;
	for(int i=1;i<=3;i++){
		if(!vis[i]){
			cout << i << '\n'; return 0;
		}
	}
}
