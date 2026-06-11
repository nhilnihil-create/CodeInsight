#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
typedef tuple<int, int, int> TI;

int main()
{
    ll n;
    cin >> n;
    int input[n-1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> input[i];
    }
    ll res = 0;
    res += input[0]+input[n-2];
    for (int i = 0; i < n - 2; i++)
    {
        res += min(input[i],input[i+1]);
    }
    cout << res << endl;

}
