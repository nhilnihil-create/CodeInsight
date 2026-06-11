#include <bits/stdc++.h>
#include <cmath>
//#define local
#ifdef local
#include "dbg-macro/dbg.h"
#endif
#define ll long long
#define pi (acos(-1))
#define rep(i, n) for (unsigned long long i = 0; i < (unsigned long long)(n); ++i)
using namespace std;
std::vector<unsigned ll> genprimevec(const unsigned ll N);

int main()
{
//thanks	
    int n;
    string s;
    cin >> n;
    cin >> s;
    unsigned ll rgb = 0;
    unsigned ll r = 0, g = 0, b = 0;
    rep(i, n)
    {
        if (s[i] == 'R') { ++r; }
        else if (s[i] == 'G')
        {
            ++g;
        }
        else
        { // b
            ++b;
        }

    }
    rgb=r*g*b;
    rep(i,n){
	    for(int j=1;j<=n;++j){
		    int ni=i-j,nj=i+j;
		    if(ni<0 ||nj>=n)break;
		    if(s[i]!=s[ni]&&s[i]!=s[nj]&&s[ni]!=s[nj]){--rgb;}//naritatanaikarahiku
	    }
    }
cout<<rgb<<endl;
    return 0;
}

ll extgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}


std::vector<unsigned ll> genprimevec(const unsigned ll N)
{
    std::vector<bool> is_prime(N + 1);
    for (unsigned ll i = 0; i <= N; i++) { is_prime[i] = true; }
    std::vector<unsigned ll> P;
    for (unsigned ll i = 2; i <= N; i++)
    {
        if (is_prime[i])
        {
            for (unsigned ll j = 2 * i; j <= N; j += i) { is_prime[j] = false; }
            P.emplace_back(i);
        }
    }
    return P;
}
