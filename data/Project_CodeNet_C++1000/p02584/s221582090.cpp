#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define pii pair<int,int>
#define que pair<pii,pii>

int X, K, D;


signed main()
{
    cin >> X >> K >> D;
    if(X < 0)X *= -1;

    if(X / D > K)
    {
        cout << X - K * D << endl;
        return 0;
    }

    if(((X - (X % D)) / D + K) % 2 == 0)cout << X % D << endl;
    else cout << -(X % D - D) << endl;

    return 0;
}
