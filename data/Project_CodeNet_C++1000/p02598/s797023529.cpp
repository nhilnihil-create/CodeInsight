#include <bits/stdc++.h>
using namespace std;

#define ll long long 

ll cnt(vector<int>& xs, int x) {
    int n = xs.size();
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (xs[i]-1)/x;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); 

    int n; cin >> n;
    int k; cin >> k;
    vector<int> xs(n);
    for (int i = 0; i < n; i++) 
        cin >> xs[i];

    int left = 1;
    int right = *max_element(xs.begin(), xs.end());
    int ans = right;
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (cnt(xs, mid) <= k) {
            ans = mid;
            right = mid-1;
        } else {
            left = mid+1;
        }
    }

    cout << ans << endl;



    return 0; 
}

