#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)

ll N;
ll sum = 0;
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        sum += i;
    }
    cout << sum << endl;
    return 0;
}
