#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    std::cout << std::fixed << std::setprecision(10);
    int N, K;
    cin >> N >> K;

    vector<double> p(N);
    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
    }

    vector<double> kitaichi(N);
    for (int i = 0; i < N; i++)
    {
        kitaichi[i] = (1 + p[i]) / 2;
    }

    // debug
    // for (int i = 0; i < N; i++)
    // {
    //     cout << kitaichi[i] << " ";
    // }

    vector<double> ruiseki(N + 1, 0);
    for (int i = 0; i < N; ++i)
    {
        ruiseki[i + 1] = ruiseki[i] + kitaichi[i];
    }

    // debug for kitaichi
    // for (int i = 0; i <= N; ++i)
    // {
    //     cout << ruiseki[i] << " ";
    // }

    // K差を見る
    double ans = 0;
    for (int i = 0; i + K <= N; i++)
    {
        if (ans < ruiseki[i + K] - ruiseki[i])
        {
            ans = ruiseki[i + K] - ruiseki[i];
        }
    }
    cout << ans << endl;
}