#include <bits/stdc++.h>

using namespace std;

long long int n, m, k, dau = 1, cuoi = -1, giua, a[200005];

bool Check(long long int m)
{
    long long int number = 0;
    for(long long int i = 1; i <= n; ++i)
    {
        number += a[i]/m;
        if(a[i] % m == 0)
            number--;
    }
    if(number <= k)
        return true;
    else
        return false;
}

long long int TKNP(long long int a[],long long int n,long long int k)
{
    while(dau <= cuoi)
    {
        giua = (dau + cuoi)/2;
        if(Check(giua) == true)
        {
            m = giua;
            cuoi = giua - 1;
        }
        else
            dau = giua + 1;
    }
    return m;
}

int main()
{
  //  freopen("Bao.inp","r", stdin);
    cin >> n >> k;
    for(long long int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        cuoi = max(a[i], cuoi);
    }
    cout << TKNP(a,n,k);
    return 0;
}
