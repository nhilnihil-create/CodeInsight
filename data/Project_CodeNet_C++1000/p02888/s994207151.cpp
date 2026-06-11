#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;


int main() {
    int n;
    scanf("%d", &n);

    vector<int> l(n);
    for(int i = 0; i < n; i++) scanf("%d", &l[i]);

    sort(l.begin(), l.end());
    ll ans = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            auto itr = lower_bound(l.begin(), l.end(), l[i] + l[j]);
            int neg = distance(itr, l.end());
            ans += n - 1 - j - neg;
        }
    }
    printf("%lld\n", ans);
}