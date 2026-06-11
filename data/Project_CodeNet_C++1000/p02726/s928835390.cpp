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
int n, x, y;
unordered_map<int, int>v;	

int main(){
	IOS
	cin >> n >> x >> y;
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int ans=min(abs(i-j), abs(i-x)+abs(j-y)+1);
			v[ans]++;
		}
	}
	for(int i=1;i<n;i++) cout << v[i] << '\n';
}
