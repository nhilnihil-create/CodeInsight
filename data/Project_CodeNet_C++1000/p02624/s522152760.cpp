#include <bits/stdc++.h>
using namespace std;

#define     F       first
#define     S       second
typedef pair<int, int>  pi;
typedef long long       ll;

const int MAX=1e7+9;
int cnt[MAX];
ll ans[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i=1; i<MAX; ++i) {
        for (int j=i; j<MAX; j+=i) {
            ++cnt[j];
        }
    }

    for (int i=1; i<MAX; ++i) {
        ans[i]=1LL*i*cnt[i]+ans[i-1];
    }

    int n;
    cin >> n;
    cout << ans[n];

    return 0;
}
