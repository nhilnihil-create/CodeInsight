#include <bits/stdc++.h>


#define FAST_INPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;


int n, k;
vector<int> nums;

bool ok(int max_size) {
    ll total_cuts=0;
    for(int i=0; i<n; i++){
        int val=nums[i];
        total_cuts+=(val/max_size+(val%max_size!=0)-1);
    }
    return total_cuts<=k;

}

void solve() {
    cin >> n >> k;
    nums=vector<int>(n);
    int mx=0;
    for (int i=0; i<n; i++) {
        cin >> nums[i];
        mx=max(mx, nums[i]);
    }
    
    int l=1, r=mx;
    int ans = INT_MAX;
    while (l<=r) {
        int mid=l+(r-l)/2;

        if(ok(mid)){
            ans=min(ans, mid);
            r=mid-1;
        } else {
            l=mid+1;
        }
    }

    cout << ans << endl;
}

int main() {
    FAST_INPUT;
    
    solve();
    
    return 0;
}
