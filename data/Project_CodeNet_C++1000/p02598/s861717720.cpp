#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;


int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int left = 0;
    int right = INF;

    while (right - left > 1) {
        int mid = (right + left) / 2;

        ll num = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] % mid == 0) num += a[i] / mid - 1;
            else num += a[i] / mid;
        }
        if (num <= k) right = mid;
        else left = mid;
    }
    cout << right << endl;
}