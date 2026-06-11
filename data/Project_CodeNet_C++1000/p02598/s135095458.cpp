#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define mp make_pair
#define ld long double
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int> > small_heap;
typedef priority_queue<int> big_heap;
const int N = 1e6 + 100;
int T;
int n, k;
int a[N];

int check(int x) {
    int num = 0;
    for (int i = 1; i <= n; i++) {
        num += (a[i] + x - 1) / x - 1;
    }
    return num <= k;
}

int main() {
    scanf("%d%d", &n, &k);
    int maxx = INT_MIN;
    for (int i = 1; i <= n; i++)scanf("%d", &a[i]), maxx = max(maxx, a[i]);
    int ans = 0;
    int l = 1, r = maxx;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid))r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}