#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
bool isprime(ll num)
{
    if(num==1)
        return false;
    if(num==2)
        return true;
    if(num%2==0)
        return false;
    ll sqnum=sqrt(num)+1;
    for(int i=3;i<=sqnum;i+=2)
    {
        if(num%i==0)
            return false;
    }
    return true;
}
vector<ll> vc;
int main ()
{
    ll a,b;
    cin>>a>>b;
    ll x=min(a,b);
    ll y=max(a,b);
    ll ans=0;
    for(ll i=1;i*i<=x;i++)
    {
        if(x%i==0){
            vc.push_back(i);
            if(i*i!=x)
                vc.push_back(x/i);
        }
    }
    for(ll i=0;i<vc.size();i++)
    {
        if(y%vc[i]==0&&isprime(vc[i]))
            ans++;
    }
    cout<<ans+1<<endl;
    return 0;
}