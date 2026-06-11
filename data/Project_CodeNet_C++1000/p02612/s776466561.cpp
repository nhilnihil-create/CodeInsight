#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); ++i)
int N;

int main()
{
    cin >> N;
    if (N % 1000 == 0)
        cout << 0 << endl;
    else
    {
        cout << (N / 1000 + 1) * 1000 - N << endl;
    }
}
