#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

const long long MOD = 1e9 + 7;
const ll num[4] = {-1, 0, 1, 0};

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, k, r, s, p;
    string str;
    cin >> n >> k >> r >> s >> p >> str;
    vector<char> vec(n);
    ll ans = 0;
    rep(i, 0, n)
    {
        char tmp;
        if (str[i] == 'r')
            tmp = 'p';
        else if (str[i] == 's')
            tmp = 'r';
        else
            tmp = 's';
        if (i < k) //問答無用で勝てる
        {
            if (tmp == 'r')
                ans += r;
            else if (tmp == 's')
                ans += s;
            else
                ans += p;
            vec[i] = tmp;
        }
        else
        {
            if (tmp == vec[i - k]) //前に出していた場合
            {
                if (vec[i - k] == 'r' && str[i + k] == 's')
                    tmp = 'p';
                else if (vec[i - k] == 'r' && str[i + k] == 'p')
                    tmp = 'p';
                if (vec[i - k] == 's' && str[i + k] == 'r')
                    tmp = 'r';
                else if (vec[i - k] == 's' && str[i + k] == 'p')
                    tmp = 'p';
                if (vec[i - k] == 'p' && str[i + k] == 'r')
                    tmp = 's';
                else if (vec[i - k] == 'p' && str[i + k] == 's')
                    tmp = 'p';
            }
            else
            {
                if (tmp == 'r')
                    ans += r;
                else if (tmp == 's')
                    ans += s;
                else
                    ans += p;
                vec[i] = tmp;
            }
            vec[i] = tmp;
        }
    }
    cout << ans << endl;
}
