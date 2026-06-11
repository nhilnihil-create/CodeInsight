#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
typedef long long ll;

using namespace std;

int main()
{
    ll x,n,i,ans=10000001;
    cin>>x>>n;
    ll a;
    set<ll>s;
    for(i=0; i<n; i++)
    {
        cin>>a;
        s.insert(a);
    }
    ll pos=10000001;
    for(i=-150; i<=150; i++)
    {
        if(s.count(i))
            continue;
        if(abs(x-i)<ans)
        {
            pos=i;
            ans=abs(x-i);
        }
    }
    cout<<pos<<endl;
}



