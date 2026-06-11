#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
    int h, w, k;
    cin >> h >> w >> k;
    string a[h];
    for(int i = 0; i < h; i++)
    {
        cin >> a[i];
    }
    int ans = 0;

    for(int mask = 0; mask<1<<(h+w); mask++)
    {
        int cnt = 0;
        for(int x=0; x<h; x++)
        {
            for(int y=0; y<w; y++)
            {
                if(a[x][y]!='#') continue;
                if(mask&((1<<x)|(1<<(h+y)))) continue;
                cnt++;
            }
        }
        if(cnt==k)
            ans++;
    }

    cout << ans << endl;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
