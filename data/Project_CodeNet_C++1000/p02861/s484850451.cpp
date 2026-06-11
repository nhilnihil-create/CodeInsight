#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using Graph = vector<vector<int>>;
using ll = long long;
using p = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<p> pn = vector<p>(n);

    rep(i, n)
    {
        int x, y;
        cin >> x >> y;
        pn[i] = p(x, y);
    }

    // 昇順にソート済みの入力
    vector<int> v = vector<int>(n);
    rep(i, n)
    {
        v[i] = i;
    }

    double total_sum = 0;
    double count = 0;
    do
    {
        count++;
        double loop_sum = 0;
        for (int i = 1; i < n; ++i)
        {
            loop_sum += sqrt(pow(pn[v[i]].first - pn[v[i - 1]].first, 2) + pow(pn[v[i]].second - pn[v[i - 1]].second, 2));
        }
        total_sum += loop_sum;
    } while (next_permutation(v.begin(), v.end()));

    cout << fixed << setprecision(7) << total_sum / count << endl;
}