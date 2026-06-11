#include <bits/stdc++.h>

using namespace std;
long long int n,dau = 1,cuoi = -1,K,giua,k; long long int a[10000001];
bool check ( int M)
{
   long long int sl= 0;
    for (long long int i = 1;i <=n;i++)
    {
        sl += a[i]/M;
        if ( a[i] % M ==0)
        {
            sl--;
        }
    }
    return sl<= K;
}

int main()
{
//freopen("test.inp","r",stdin);
    cin >> n >> K;
    for (long long int i = 1;i <= n;i++)
    {
        cin >> a[i];
        cuoi = max(cuoi,a[i]);
    }
    while (dau <= cuoi)
    {
        giua = (dau +cuoi)/2;
        if (check(giua) == true)
        {
            k = giua;
            cuoi = giua -1;
        }
        else
        {
            dau= giua+1;
        }
    }
    cout <<k << endl;
    return 0;
}
