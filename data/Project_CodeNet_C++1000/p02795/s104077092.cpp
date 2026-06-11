#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 1e6 + 7;
ll a[1002][1002], t, n, m, x;
void test()
{
    for(int i=0;i<1000;i++)
    {
        a[0][i]=1;
        a[i][0]=1;
    }
    for(int i=1;i<1000;i++)
    {
        for(int j=1;j<1000;j++)
            a[i][j]=a[i][j-1]+a[i-1][j-1];
    }

    cin >> t;
    for(int i=0; i < t; i++)
    {
        cin >> n >> m;
        for(int j=0;j<1000;j++)
        {
            m = m - a[n-1][j];
            if(m<=0)
            {
                x = j;
                break;
            }
        }
    cout << x + 1<<'\n';
    }
}
void sol()
{
    cin >> n >> m >> x;
    t = max(n, m);
    cout << (x + t - 1) / t;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sol();
    //getch();
}
