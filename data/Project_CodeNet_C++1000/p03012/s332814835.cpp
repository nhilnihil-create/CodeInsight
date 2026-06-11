#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    int left = 0;
    int right = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        right += v[i];
    }
    int res = 100000;
    rep0(i, N)
    {
        if (abs(left - right) < res)
        {
            res = abs(left - right);
        }
        left += v[i];
        right -= v[i];
    }
    cout << res;
}
