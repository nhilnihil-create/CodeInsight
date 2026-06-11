#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int N;
    cin >> N;

    vector<int> d(N);
    for (int i = 0; i < N; i++)
    {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    int half = N / 2;
    int begin = d[half - 1];
    int end = d[half];

    int ans = end - begin;
    cout << ans << endl;
    return (0);
}