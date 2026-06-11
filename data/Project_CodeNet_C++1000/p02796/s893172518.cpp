#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>

int N;
int X[100010], L[100010];
vector<pii> V;

signed main()
{
    cin >> N;
    rep(i, N)
    {
        int x, l;
        cin >> x >> l;
        V.push_back({x + l, x - l});
    }

    sort(V.begin(), V.end());

    int ans = 0;
    int now = -2000000000;
    for(auto ele : V)
    {
        if(now <= ele.second)
        {
            ans++;
            now = ele.first;
        }
    }

    cout << ans << endl;

    return 0;
}
