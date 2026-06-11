#include <bits/stdc++.h>
using namespace std;

#define R (long long)(1e9 + 7)
#define INF (long long)(1e16L + 5)
#define ll long long
#define grid vector<vector<ll>>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h, w, m;
    cin >> h >> w >> m;
    
    vector<pair<int, int>> p(m);
    for(pair<int, int>& x : p)
        cin >> x.first >> x.second;
    
    map<int, vector<int>> x, y;
    for(auto point : p)
    {
        x[point.first].push_back(point.second);
        y[point.second].push_back(point.first);
    }
    
    int ans = 0;
    for(auto point : p)
    {
        ans = max(ans, (int)x[point.first].size() + (int)y[point.second].size() - 1);
    }

    int mx_x = 0;
    for(auto e : x)
    {
        mx_x = max(mx_x, (int)(e.second.size()));
    }

    map<int, int> ys;
    int cnt = 0;

    for(auto e : x)
    {
        if(e.second.size() == mx_x)
        {
            for(auto y : e.second)
                ys[y]++;
            cnt++;
        }
    }

    for(int i = 1; i <= max(w, h); i++)
    {
        if(ys[i] != cnt)
        {
            ans = max(ans, (int)y[i].size() + mx_x);
        }
    }

    cout << ans << '\n';

    return 0;
}