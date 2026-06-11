#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define db long double
#define all(a) a.begin(),a.end()
#define f(i,l,u) for(ll i=l;i<u;i++)
#define lb lower_bound
#define ub upper_bound
#define pb push_back

int main() {

ll n;
cin>>n;
ll val[n+1]={0};
f(i,1,101)
{
    f(j,1,101)
    {
        f(k,1,101)
        {
                       ll v1=(i+j)*(i+j);
            ll v2=(k+j)*(k+j);
            ll v3=(i+k)*(i+k);
            ll sum=(v1+v2+v3)/2;
            if(sum<=n)
            val[sum]++;
           
            
        }
    }
}
f(i,1,n+1)
cout<<val[i]<<endl;
    
    return 0;
}