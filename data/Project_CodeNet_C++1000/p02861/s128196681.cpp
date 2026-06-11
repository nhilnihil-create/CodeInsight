#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define downque(que) priority_queue<ll> que;
#define upque(que) priority_queue<ll, vector<int>, greater<int>> que;
typedef long long ll;
typedef vector<vector<int>> Matrix;
const int MOD = 1e9 + 7;

//calculate distance between an point to another point
double calc_dis(double x1, double y1, double x2, double y2)
{
    double dis = pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0);
    dis = pow(dis, 0.5);
    return dis;
}

int main(void)
{
    int n, count = 0;
    double all_dis = 0;
    cin >> n;

    //xy retains coordinates of points
    vector<vector<double>> xy(n, vector<double>(2));
    vector<int> array(n);

    REP(i, n)
    {
        array[i] = i;
        cin >> xy[i][0] >> xy[i][1];
    }

    do
    {
        REP(i, n - 1)
        {
            //add distance between town[array[i]] and town[array[i+1]] to all_dis
            all_dis += calc_dis(xy[array[i]][0], xy[array[i]][1], xy[array[i + 1]][0], xy[array[i + 1]][1]);
        }
        count++;
    } while (next_permutation(array.begin(), array.end()));

    printf("%.8lf\n", all_dis / count);
    return 0;
}
