#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int a[200010];

int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];

    int p = 1;
    for (int i=0;i<n;i++) {
        if (a[i]==p) p++;
    }
    cout << (p==1? -1: n-p+1) << endl;
}
