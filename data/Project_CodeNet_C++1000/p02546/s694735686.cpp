#include <bits/stdc++.h>
#define ll long long
const long double PI=acos(-1);
using namespace std;
void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}
bool p(int a,int b)
{
    return a>b;
}
int modpow(int a,int b,int c)
{
    if(b==0)
        return 1%c;
    int u = modpow(a,b/2,c);
    u=(u*u)%c;
    if(b&1)
        u=(u*a)%c;
    return u;
}
bool cmp(const pair<ll,ll>&q,const pair<ll,ll>&f)
{
    return q.second>f.second;
}
ll prime(ll x)
{
    if(x<2)
    {
        return false;
    }
    else
    {
        for(int i=2;i*i<=x;i++)
        {
            if(x%i==0)
            {
                return false;
            }
        }
        return true;
    }
}

int main() {
    fast();
    string x;
    cin>>x;
    if(x[x.length()-1]=='s')
        cout<<x+"es"<<endl;
    else
        cout<<x+"s"<<endl;
}