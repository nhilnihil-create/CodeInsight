#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))
#define F first
#define S second
#define int ll


int32_t main(){
    FAST
    int n; cin >> n;
    vector<int> vec1;
    map<int, vector<int> > mp;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        vec1.pb(arr[i] + i);
        mp[i - arr[i]].pb(i);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += mp[vec1[i]].size() - (upper_bound(mp[vec1[i]].begin(), mp[vec1[i]].end(), i) - mp[vec1[i]].begin());
    }
    cout << ans;
    return 0;
}
