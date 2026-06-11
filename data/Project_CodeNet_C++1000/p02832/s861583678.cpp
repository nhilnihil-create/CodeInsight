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

    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    // debug
    // for (int i = 1; i < N + 1; i++)
    // {
    //     printf("%d ", i);
    // }
    // printf("\n");

    // for (int i = 1; i < N + 1; i++)
    // {
    //     printf("%d ", a[i]);
    // }

    int ans = 0;
    int checker = 1;
    for (int i = 0; i < N; i++)
    {
        if (a[i] != checker)
        {
            ans++;
        }
        else
        {
            checker++;
        }
    }
    if (checker == 1 && ans > 0)
    {
        ans = -1;
    }
    cout << ans << endl;
    return (0);
}