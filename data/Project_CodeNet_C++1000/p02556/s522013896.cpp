#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>

int N;
int X[200010], Y[200010];

signed main()
{
    cin >> N;
    rep(i, N)
    {
        int x, y;
        cin >> x >> y;
        X[i] = x + y;
        Y[i] = x - y;
    }

    sort(X, X + N);
    sort(Y, Y + N);

    cout << max(X[N - 1] - X[0], Y[N - 1] - Y[0]) << endl;

    return 0;
}
