#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, M;
void func()
{
    cin >> N;
    vector<vector<pair<int, int>>> A(N + 1);
    int v[N + 1] = {}; //0が不親切、1が親切
    int ans = 0;       //正直者の数
    int tmp, tmpx, tmpy;
    rep(i, 1, N + 1)
    {
        cin >> tmp;
        rep(j, 0, tmp)
        {
            cin >> tmpx >> tmpy;
            A[i].push_back(make_pair(tmpx, tmpy));
        }
    }
    rep(i, 0, N + 1) //親切な人の数
    {
        rep(j, 1, N - i + 1)
        {
            v[j] = 0;
        }
        rep(j, N - i + 1, N + 1)
        {
            v[j] = 1;
        }
        do
        {
            // rep(j, 1, N + 1)
            // {
            //     cout << v[j] << ' ';
            // }
            // cout << endl;
            bool check = true;
            rep(k, 1, N + 1)
            {
                if (!v[k])
                    continue;
                rep(l, 0, A[k].size())
                {
                    if (v[A[k][l].first] != A[k][l].second)
                    {
                        check = false;
                        break;
                    }
                }
                if (!check)
                    break;
            }
            if (check)
            {
                ans = (i > ans) ? i : ans;
            }
        } while (next_permutation(&v[1], &v[N + 1]));
    }
    cout << ans << endl;
}
int main()
{
    func();
}