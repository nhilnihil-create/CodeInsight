#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using VVI = vector<vector<int>>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (char i = '0'; i <= '9'; i++)
    {
        for (char j = '0'; j <= '9'; j++)
        {
            for (char k = '0'; k <= '9'; k++)
            {
                string number = "000";
                number[0] = i;
                number[1] = j;
                number[2] = k;
                int idx = 0;
                for (int m = 0; m < n; m++)
                {
                    if (number[idx] == s[m])
                    {
                        idx++;
                        if (idx == 3)
                        {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}