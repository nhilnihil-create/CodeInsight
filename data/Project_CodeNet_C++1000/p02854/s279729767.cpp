#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<long long int> sa(n+1);
    for(int i=0; i<n; i++){
        sa[i+1] = sa[i] + a[i];
    }

    int left  = prev(upper_bound(sa.begin(),sa.end(),sa[n] / 2)) - sa.begin();
    int right = upper_bound(sa.begin(),sa.end(),sa[n] / 2) - sa.begin();
    //cout << left << " " << right << endl;

    long long int ans = 1e18;// INF
    ans = min(ans, sa[n] - 2 * sa[left]);
    ans = min(ans, 2 * sa[right] - sa[n]);
    cout << ans << endl;
    return 0;
}