#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

    ll n,i,j,k,l,a,b;
    cin>>n>>a>>b;
   ll ans=n/(a+b);
   ans*=a;
   k=n%(a+b);
   ans+=min(a,k);
   cout<<ans<<endl;
    return 0;
}
