#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll l, n , k , x , a, b, c ,d,sum;
vector<int>v;
const ll MOD = 1e9 + 7;
const ll N = 2000;
const ll K = 2000;
ll C[N+2][K+2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(C, 0 , sizeof C);
    C[0][0]=1;
    C[1][0]=1;
    for(int i = 0 ; i <=N ;i++)
    {
        C[i][0]=1;
    }
    for(int i = 1 ; i <= N ;i++)
    {
        for(int j = 1 ; j<=K ;j++)
        {
            C[i][j]=(C[i-1][j-1]+ C[i-1][j])%MOD;

        }
    }
    cin >> n >> k;
    a=n-k+1;
    for(int i = 1 ; i <=k ; i++)
    {
       b= C[a][i]%MOD;
       c=C[k-1][i-1]%MOD;
       if(i==1)
       {
           c=1;
       }
       cout << (b*c)%MOD << "\n";
    }
    return 0;
}