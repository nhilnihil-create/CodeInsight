#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define f(i,l,u) for(ll i=l;i<u;i++)
int main() {
ll a,b,c,d;
cin>>a>>b>>c>>d;
ll at[2];
ll bt[2];
at[0]=a;
at[1]=b;
bt[0]=c;
bt[1]=d;
ll ans=-1e18;
//cout<<ans<<endl;
ans--;
//cout<<ans<<endl;
f(i,0,2)
{
f(j,0,2)

{
    //cout<<"I= "<<i<<" j= "<<j<<endl;
    ans=max(ans,at[i]*bt[j]);
//cout<<ans<<endl;
    
}
}
cout<<ans<<endl;


}