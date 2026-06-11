#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define part cout<<"------------------\n";
#define debug(x) cout<<#x<<" : "<<x<<endl;

inline LL f(LL n)
{

    return (n*(n+1))/2;
}

int main()
{
    LL n,i,j,k,t,stemp;
    cin>>n>>k;
    LL cnt=0;
    for(i=k;i<=n+1;i++)
    {
        LL add=f(n)-f(n-i)-f(i-1)+1;
       // debug(i);
        //debug(add);
       // part;
        cnt+=add;
        cnt%=(LL)(1e9+7);
    }
    cout<<cnt<<endl;



}