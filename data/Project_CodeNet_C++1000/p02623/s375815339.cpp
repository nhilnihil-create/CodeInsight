#include <bits/stdc++.h>
using namespace std;

#define     F       first
#define     S       second
typedef pair<int, int>  pi;
typedef long long       ll;

const int MAX=2e5+9;
int n, m, k;
ll pref1[MAX], pref2[MAX];

int BSFind(int rest) {
    int low=0, high=m, res=0;

    while (low<=high) {
        int mid=((low+high)/2);

        if (pref2[mid]<=rest) {
            res=mid;
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i=1; i<=n; ++i) {
        int x;
        cin >> x;
        pref1[i]=x+pref1[i-1];
    }

    for (int i=1; i<=m; ++i) {
        int x;
        cin >> x;
        pref2[i]=x+pref2[i-1];
    }

    int ans=0;
    for (int i=0; i<=n; ++i) {
        int rest=k-pref1[i];
        if (rest<0) {
            break;
        }

        int can=BSFind(rest);
        ans=max(ans, i+can);
    }

    cout << ans;

    return 0;
}
