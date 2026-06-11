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

#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define repd(i, n) for (ll i = (n)-1; i >= 0; --i)
#define INF 10e12
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    map<char, int> m;
    set<char> st;
    rep(i, s.length()) m[s[i]]++, st.insert(s[i]);
    if (st.size() != 2)
        cout << "No" << endl;
    else
    {
        for (auto i : m)
        {
            if (i.second != 2)
            {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }
}