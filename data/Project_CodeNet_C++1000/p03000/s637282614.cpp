#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
    int N, X;
    cin >> N >> X;
    vector<int> input(N);
    rep0(i, N)
    {
        cin >> input[i];
    }
    int D = 0;
    int res = 0;
    rep0(i, N)
    {
        res++;
        D += input[i];
        if (D > X)
        {
            break;
        }
    }
    if (D <= X)
    {
        res++;
    }
    cout << res;
}
