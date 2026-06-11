#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int> > small_heap;
typedef priority_queue<int> big_heap;
int n, k;
ll s[200009];
map<ll, ll> mmp;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        s[i] = s[i - 1] + x;
    }
    mmp[0] = 1;
    ll ans = 0;
    int l = 0;
    for (int i = 1; i <= n; i++) {
        if (i >= k) {
            mmp[(s[l] - l + k) % k]--, l++;
        }
        ans += mmp[(s[i] - i + k) % k];
        mmp[(s[i] - i + k) % k]++;
    }
    printf("%lld\n", ans);
    return 0;
}