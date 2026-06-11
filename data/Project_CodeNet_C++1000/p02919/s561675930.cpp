#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100010;

struct BIT {
    int n;
    vi bit;
    BIT(int num):bit(num+1,0){n=num;}
    void add(int i, int w){
        for(int x=i; x<=n; x+=x&-x) bit[x]+=w;
    }
    int sum(int i){
        int ret=0;
        for(int x=i; x>0; x-=x&-x) ret+=bit[x];
        return ret;
    }
    int sum(int l, int r){return sum(r)-sum(l);}
};

ll search(BIT &tree, ll n, ll find) {
	if(find < tree.sum(1)) return 0;
	if(find == 0) return 0;
	if(find > tree.sum(n)) return n + 1;
	ll left = 1, right = n;
	ll ret = n + 2;
	while(left <= right) {
		ll mid = (left + right) / 2;
		if(tree.sum(mid) >= find) {
			ret = min(mid, ret);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return ret;
}

void show_tree(BIT &tree, int n) {
	rep1(i, n) cout << tree.sum(i) << ' ';
	cout << endl;
}

int main() {
	ll n;
	cin >> n;
	ll p[N], pos[N];
	rep1(i, n) {
		cin >> p[i];
		pos[p[i]] = i;
	}
	BIT tree(n);
	ll ans = 0ll;
	tree.add(pos[n], 1);
	for(ll i = n - 1; i >= 1; i--) {
		ll j = pos[i];
		ll cur_sum = tree.sum(j);
		ll l2 = search(tree, n, cur_sum - 1);
		ll l1 = search(tree, n, cur_sum);
		ll r1 = search(tree, n, cur_sum + 1);
		ll r2 = search(tree, n, cur_sum + 2);
		ans += i * ((l1 - l2) * (r1 - j) + (r2 - r1) * (j - l1));
		tree.add(j, 1);
	}
	cout << ans << endl;
}
