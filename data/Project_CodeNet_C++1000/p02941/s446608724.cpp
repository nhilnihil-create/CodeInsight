#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9+7;
const int BASE = 27;
const int N = 200001;
const ll oo = 1e18;
const double EPS = 1e-9;

int n , a[N],b[N];

priority_queue<pii> q;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i){
		scanf("%d",a+i);
	}
	for (int i = 0; i < n; ++i){
		scanf("%d",b+i);
		q.push(mp(b[i],i));
	}
	ll ans = 0;
	while(q.size()){
		pii f = q.top();
		q.pop();
		if(b[f.y] == a[f.y])continue;
		if(a[f.y] > b[f.y]){
			puts("-1");
			return 0;
		}
		int nxt_idx = (f.y+1)%n;
		int prv_idx = (f.y-1+n)%n;
		int rem = b[nxt_idx]+b[prv_idx];
		int g = (b[f.y]-a[f.y])/rem;
		int newVal = f.x-g*rem;
		b[f.y] =  newVal;
		ans += g;
		if(!g && newVal != a[f.y]){
			puts("-1");
			return 0;
		}
		q.push(make_pair(newVal,f.y));
	}
	printf("%lld\n", ans);
	return 0;
}