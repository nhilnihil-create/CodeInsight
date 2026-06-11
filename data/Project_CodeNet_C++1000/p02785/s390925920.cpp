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
ll n, k, h[200005], ans=0;

bool cmp(int a, int b){
	return a>b;
}

int main(){
	IOS
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> h[i];
	}
	sort(h, h+n, cmp);
	for(int i=0;i<n;i++){
		if(k>0){
			k--;
			continue;
		}
		ans+=h[i];
	}
	cout << ans << '\n';
}
