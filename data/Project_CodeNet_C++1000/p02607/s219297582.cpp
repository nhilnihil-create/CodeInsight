#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define fi first
#define se second
#define pf push_front
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define debug(val) cerr << "Value of " << #val << " : " << val << '\n';
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll nax = 0;

int main(){
	IOS	
	int n, arr[105], ans=0;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> arr[i];
		if(i&1 && arr[i]&1) ans++;
	}
	cout << ans << '\n';
}
