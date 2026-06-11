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
    string s;
    cin >> s;
    int to_L[s.size()], to_R[s.size()];
    int cnt = 0;
    rep(i, s.size())
    {
        if (s[i] == 'R')
            cnt = i;

        to_R[i] = cnt;
    }
    cnt = 0;
    for (int i = (s.size() - 1); i >= 0; i--)
    {
        if (s[i] == 'L')
            cnt = i;
        to_L[i] = cnt;
    }
    vector<int> pos(s.size(), 0);
    rep(i, s.size())
    {
        if (s[i] == 'L')
        {
            if ((i - to_R[i]) % 2 == 0)
            {
                pos[to_R[i]]++;
            }
            else
            {
                pos[to_R[i] + 1]++;
            }
        }
        else
        {
            if ((to_L[i] - i) % 2 == 0)
            {
                pos[to_L[i]]++;
            }
            else
            {
                pos[to_L[i] - 1]++;
            }
        }
    }
    rep(i, s.size())
    {
        cout << pos[i] << ' ';
    }
    cout << endl;
    return 0;
}