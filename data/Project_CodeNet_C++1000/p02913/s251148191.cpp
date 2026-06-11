#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;

template <typename T>
void print(const T &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

typedef unsigned long long ull;
#define B1 100000007
#define B2 1000000007

bool rolling_hash(string const &S, int t_start, int m)
{
    int s_start = t_start + m;

    // B^mを用意する
    ull pow_B_m_1 = 1, pow_B_m_2 = 1;
    for (int k = 0; k < m; k++)
    {
        pow_B_m_1 *= B1, pow_B_m_2 *= B2;
    }

    // sとtの先頭m文字のハッシュ値sh,thを計算
    ull sh1 = 0, sh2 = 0, th1 = 0, th2 = 0;
    for (int k = 0; k < m; k++)
    {
        th1 = th1 * B1 + S[t_start + k], th2 = th2 * B2 + S[t_start + k];
        sh1 = sh1 * B1 + S[s_start + k], sh2 = sh2 * B2 + S[s_start + k];
    }

    // sをずらしてハッシュ値を更新
    for (int k = 0; s_start + k < S.length(); k++)
    {
        if (sh1 == th1 && sh2 == th2)
            return true;
        if (k + s_start < S.length())
        {
            sh1 = sh1 * B1 + S[s_start + m + k] - S[s_start + k] * pow_B_m_1;
            sh2 = sh2 * B2 + S[s_start + m + k] - S[s_start + k] * pow_B_m_2;
        }
    }
    return false;
}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int left = -1, right = (n / 2) + 1;
    while (right - left > 1)
    {
        // cout << "left:" << left << " right:" << right << endl;
        int length = (left + right) / 2;
        bool exist_same = false;
        // 基準文字列の始点
        for (int i = 0; i < n && !exist_same; i++)
        {
            if (rolling_hash(s, i, length))
            {
                exist_same = true;
                break;
            }
        }
        if (exist_same)
        {
            left = length;
        }
        else
        {
            right = length;
        }
    }
    cout << left << endl;
    return 0;
}
