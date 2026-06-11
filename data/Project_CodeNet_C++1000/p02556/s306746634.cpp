#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);

const int N = 2e5+5, M = 1e6+6, OO = 0x3f3f3f3f;
int tc;
int n;
pair<ll, ll> arr[N];
int main()
{
    FIO
    cin>>n;
    ll ans = -OO;
    vector<ll> sums, diffs;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i].first>>arr[i].second;
       sums.push_back(arr[i].first + arr[i].second);
       diffs.push_back(arr[i].first - arr[i].second);
    }
    sort(sums.begin(), sums.end()); sort(diffs.begin(), diffs.end());
    cout<<max(sums[n-1] - sums[0], diffs[n-1] - diffs[0]);
    
    return 0;
}