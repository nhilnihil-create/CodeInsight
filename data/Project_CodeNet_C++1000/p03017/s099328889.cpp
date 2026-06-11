#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
typedef long long ll;
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (ll i = begin; i < (ll)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    string s;
    cin >> s;

    // 岩が2個並んでる場合はNG
    rep(A, i, C)
    {
        if (s.at(i) == '#' && s.at(i + 1) == '#')
        {
            cout << "No" << endl;
            return 0;
        }
    }
    rep(B, i, D)
    {
        if (s.at(i) == '#' && s.at(i + 1) == '#')
        {
            cout << "No" << endl;
            return 0;
        }
    }

    // すぬけ君がふぬけ君を追い抜く時は3マス以上の空きスペースが必要
    if (C > D)
    {
        for (ll i = B - 1; i <= D - 1; i++)
        {
            string ss = s.substr(i - 1, 3);
            if (ss == "...")
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
}