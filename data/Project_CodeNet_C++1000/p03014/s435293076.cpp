#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> inline bool chmax(T &a, T b)
{
    if(a < b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W;
    cin >> H >> W;
    vector<string> mp(H);
    for(int i=0; i<H; i++) cin >> mp.at(i);

    vector<vector<int>> hidari(H, vector<int>(W, 0));
    for(int i=0; i<H; i++)
    {
        int cnt = 0;
        for(int j=0; j<W; j++)
        {
            if(mp[i][j] == '.') cnt++;
            else cnt = 0;
            hidari[i][j] = cnt;
        }
    }

    vector<vector<int>> migi(H, vector<int>(W, 0));
    for(int i=0; i<H; i++)
    {
        int cnt = 0;
        for(int j=W-1; j>=0; j--)
        {
            if(mp[i][j] == '.') cnt++;
            else cnt = 0;
            migi[i][j] = cnt;
        }
    }

    vector<vector<int>> ue(H, vector<int>(W, 0));
    for(int j=0; j<W; j++)
    {
        int cnt = 0;
        for(int i=0; i<H; i++)
        {
            if(mp[i][j] == '.') cnt++;
            else cnt = 0;
            ue[i][j] = cnt;
        }
    }

    vector<vector<int>> shita(H, vector<int>(W, 0));
    for(int j=0; j<W; j++)
    {
        int cnt = 0;
        for(int i=H-1; i>=0; i--)
        {
            if(mp[i][j] == '.') cnt++;
            else cnt = 0;
            shita[i][j] = cnt;
        }
    }

    int ans = 0;
    for(int i=0; i<H; i++)
    {
        for(int j=0; j<W; j++)
        {
            chmax(ans, hidari[i][j] + migi[i][j] + ue[i][j] + shita[i][j] - 3);
        }
    }
    cout << ans << endl;

    return 0;
}
