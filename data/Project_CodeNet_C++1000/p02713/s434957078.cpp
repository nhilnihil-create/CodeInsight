#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
    int i, j, k, y, n;
    cin>>n;
    ll sum = 0;
    for(i = 1; i<=n; i++)
    {
        for(j = 1; j<=n; j++)
        {
            for(k = 1; k<=n; k++)
            {
                y = __gcd(i, j);
                y = __gcd(y, k);
                sum+=y;
            }
        }
    }

    cout<<sum<<endl;
}
