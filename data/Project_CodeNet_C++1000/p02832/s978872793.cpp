#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
        ll t,n,m,i,a,b;
        cin>>n;
        vector<ll> v(n+1);
        for(i=1;i<=n;i++)
        {
            cin>>v[i];
        }
        a=1;b=0;
        for(i=1;i<=n;i++)
        {
            if(v[i]==a)
            {
                b++;
                a++;
            }
        }
        if(b==0)
            cout<<-1;
        else
            cout<<n-b;
}
    
