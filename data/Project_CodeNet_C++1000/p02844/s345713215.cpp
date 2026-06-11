#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pos[10];
    rep(i, n)
    {
        pos[s[i] - '0'].push_back(i);
    }
    int cnt = 0;
    rep(i, 1000)
    {
        int first = i / 100;
        int second = i / 10;
        second %= 10;
        int third = i % 10;
        if (pos[first].size() == 0 || pos[second].size() == 0 || pos[third].size() == 0)
            continue;
        int f_pos = pos[first][0];
        int s_pos = 0;
        rep(j, pos[second].size())
        {
            if (pos[second][j] > f_pos)
            {
                s_pos = pos[second][j];
                break;
            }
        }
        if (s_pos == 0)
            continue;
        rep(j, pos[third].size())
        {
            if (pos[third][j] > s_pos)
            {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}