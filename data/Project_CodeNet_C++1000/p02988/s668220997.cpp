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
    vector<int> input(N);
    rep0(i, N)
    {
        cin >> input[i];
    }
    int res = 0;
    for (int i = 0; i < N - 2; i++)
    {
        if ((input[i] < input[i + 1] && input[i + 1] < input[i + 2]) || (input[i] > input[i + 1] && input[i + 1] > input[i + 2]))
        {
            res++;
        }
    }
    cout << res << endl;
}
