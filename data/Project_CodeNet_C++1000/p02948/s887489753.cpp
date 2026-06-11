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
    int n, m;
    cin >> n >> m;
    vector<int> arr[m + 1];
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        if(a > m)continue;
        arr[a].pb(b);
    }
    priority_queue<int> pq;
    int ans = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < arr[i].size(); j++){
            pq.push(arr[i][j]);
        }
        if(pq.empty())continue;
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
    return 0;
}
