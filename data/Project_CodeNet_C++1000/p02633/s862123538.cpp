#include<bits/stdc++.h>
typedef long long     ll;
using namespace std;
int main()
{
    ll n,sum=0;
    cin>>n;
    if(n==360)
        cout << 2 << endl;
    else
    {
        for(int i=1;i<=100000;i++)
        {
             sum+=n;
             if(sum%360==0)
             {
                  cout << i << endl;
                  break;
             }
        }
    }
}
