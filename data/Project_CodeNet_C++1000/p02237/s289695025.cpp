#include <bits/stdc++.h>
#include <numeric>
#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define SORT_INV(c) sort((c).begin(), (c).end(), greater<int>())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG true
#define LL long long
#define Num 1000000007
// sort(a.begin(), a.end(), std::greater<int>());
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n][n] = {0};
    rep(i,n){
        rep(j,n){
            a[i][j]=0;
        }
    }
    rep(i, n)
    {
        int u, k;
        cin >> u >> k;
        rep(j, k)
        {
            int hoge;
            cin >> hoge;
            a[u-1][hoge-1] = 1;
        }
    }
    rep(i, n)
    {
        rep(j, n)
        {
            cout << a[i][j];
            if (j != n - 1)
                cout << " ";
        }
        cout << endl;
    }
}
