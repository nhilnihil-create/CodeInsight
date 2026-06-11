#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
int N;
ll fact(int k)
{
    if (k == 1)
    {
        return 1;
    }
    return k * fact(k - 1);
}
double dist(int x1, int x2, int y1, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main()
{
    cin >> N;
    vector<int> x(N);
    vector<int> y(N);
    double f = fact(N) / N * 2;
    // cout << fact(N) << endl;
    // cout << f << endl;
    rep(i, 0, N)
    {
        cin >> x[i] >> y[i];
    }
    double sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            sum += dist(x[i], x[j], y[i], y[j]) * f;
        }
    }
    // cout << sum << endl;
    cout << fixed << setprecision(10) << (sum) / fact(N) << endl;
    return 0;
}