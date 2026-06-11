#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define pb push_back
#define si second
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  mod 100000000000
#define double long double
#define all(o) o.begin(),o.end()
using namespace std;

int power(int x, int y)
{
    int res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1; // y = y/2
        x = (x*x) % mod;
    }
    return res%mod;
}
int inv(int n)
{
    return power(n,mod-2)%mod;
}



int32_t main() {

  //  fast

    int c=0,n,ele,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>ele;
        if(ele%2 && i%2)
            c++;
    }
    cout<<c<<"\n";
}
