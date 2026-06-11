#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
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

const ull MASK30 = (1UL << 30) - 1;
const ull MASK31 = (1UL << 31) - 1;
const ull MOD = (1UL << 61) - 1;
const ull MASK61 = MOD;
const ull POSITIVIZER = MOD * ((1UL << 3) - 1);
const unsigned int Base = 1000000007;
ull powMemo[5001];
ull hashes[5001];

//mod 2^61-1を計算する関数
ull CalcMod(ull x)
{
    ull xu = x >> 61;
    ull xd = x & MASK61;
    ull res = xu + xd;
    if (res >= MOD)
        res -= MOD;
    return res;
}

//a*b mod 2^61-1を返す関数(最後にModを取る)
ull Mul(ull a, ull b)
{
    ull au = a >> 31;
    ull ad = a & MASK31;
    ull bu = b >> 31;
    ull bd = b & MASK31;
    ull mid = ad * bu + au * bd;
    ull midu = mid >> 30;
    ull midd = mid & MASK30;
    return CalcMod(au * bu * 2 + midu + (midd << 31) + ad * bd);
}

ull Slice(int start, int length)
{
    return CalcMod(hashes[start + length] + POSITIVIZER - Mul(hashes[start], powMemo[length]));
}

void rolling_hash(string const &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        hashes[i + 1] = CalcMod(Mul(hashes[i], Base) + s[i]);
    }
    powMemo[0] = 1;
    for (int i = 1; i < 5001; i++)
        powMemo[i] = CalcMod(Mul(powMemo[i - 1], Base));
}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    rolling_hash(s);
    // 二分探索
    int left = -1, right = (n / 2) + 1;
    while (right - left > 1)
    {
        int length = (left + right) / 2;
        bool exist_same = false;

        // 基準文字列の始点
        for (int i = 0; i < n && !exist_same; i++)
        {
            for (int j = i + length; j < n; j++)
            {
                if (j + length > n)
                {
                    break;
                }
                if (Slice(i, length) == Slice(j, length))
                {
                    exist_same = true;
                }
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
