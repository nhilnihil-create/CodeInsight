#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const int mod = 1e9 + 7;

long double calc(long double x1, long double x2, long double y1, long double y2)
{
    long double dis = 0;
    long double dx = x1 - x2;
    long double dy = y1 - y2;
    dis = sqrt(pow(dx, 2) + pow(dy, 2));
    return dis;
}

int main()
{
    long double ans = 0;
    int n;
    cin >> n;
    vector<vector<long double>> xy(n, vector<long double>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> xy.at(i).at(0);
        cin >> xy.at(i).at(1);
    }

    vector<vector<long double>> distance(n, vector<long double>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            distance.at(i).at(j) = calc(xy.at(i).at(0), xy.at(j).at(0), xy.at(i).at(1), xy.at(j).at(1));
        }
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        p.at(i) = i;
    }
    int num = 0;

    do
    {
        long double sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != n - 1)
            {
                sum += distance.at(p.at(i)).at(p.at(i + 1));
            }
            else
            {
                break;
            }
        }
        ans += sum;
        num++;

    } while (next_permutation(p.begin(), p.end()));
    ans /= num;
    cout << std::fixed << std::setprecision(10) << ans << endl;
}