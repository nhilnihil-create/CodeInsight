#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <ostream>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main()
{
    int N;
    int t;
    cin >> N;
    int cnt = 0;
    vector<int> p;
    vector<int> q;
    vector<int> nums(N);
    int ans[2] = {0, 0};
    iota(nums.begin(), nums.end(), 1);
    for (int i = 0; i < N; i++)
    {
        cin >> t;
        p.push_back(t);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> t;
        q.push_back(t);
    }
    do
    {
        cnt++;
        if (nums == p)
        {
            ans[0] = cnt;
        }
        if (nums == q)
        {
            ans[1] = cnt;
        }
    } while (next_permutation(nums.begin(), nums.end()));

    cout << abs(ans[0] - ans[1]) << endl;
}