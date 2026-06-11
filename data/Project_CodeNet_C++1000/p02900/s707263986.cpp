#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> v;
void seive()
{
    bool ar[1000008];
    ll i,j;
    memset(ar,true,sizeof(ar));
    for( i=3;i*i<=1000007;i=i+2)
    {
        if(ar[i]==true)
        {
        for( j=i*i;j<=1000007;j=j+i)
        {
            ar[j]=false;
        }
        }
    }
    v.push_back(2);
    for( i=3;i<=1000007;i=i+2)
    {
        if(ar[i]==true)
            v.push_back(i);
    }
}
int main()
{
    seive();
    ll a,b,i,j,x,y;
    scanf("%lld%lld",&a,&b);
    x=__gcd(a%b,b);
    set<int> s;
    s.insert(1);
    for(i=0;v[i]*v[i]<=x;i++)
    {
        while(x%v[i]==0)
        {
            s.insert(v[i]);
            x=x/v[i];
        }
    }
    if(x>1)
    {
        s.insert(x);
    }
    printf("%d",s.size());
    return 0;

}
