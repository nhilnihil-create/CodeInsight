#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;


int c(int x)
{
    int m = 0, t = 0, ret = 0;
    while(m <= x)
    {
        ret++;
        t++;
        m+=t;
    }
    return ret-1;
}

void solve()
{
    ll n;
    cin >> n;
    ll ogn = n;
    ll cnt = 0, twos = 0;

    while(n%2==0)
    {
        twos++;
        n/=2;
    }
    cnt += c(twos);

    for(ll i = 3; i*i<ogn; i+=2)
    {
        twos = 0;
        while(n%i==0)
        {
            twos++;
            n/=i;
        }
        cnt += c(twos);
    }
    if(n>1)
        cnt++;
    cout << cnt << endl;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    solve();
    return 0;
}
