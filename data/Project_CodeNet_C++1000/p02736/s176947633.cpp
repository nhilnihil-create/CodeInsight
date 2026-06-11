#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=1e6+5;

ll fac[sz];

int n;
int a[sz];
char s[sz];

void prec()
{
    for(ll i=2; i<sz; i++) {
        ll n=i, k=0;
        while(!(n&1)) n>>=1, k++;
        fac[i] = fac[i-1] + k;
    }
}

int cmb(int n, int r)
{
    ll x = fac[n] - fac[n-r] - fac[r];
    if(x) x = 0;
    else x = 1;
    return x;
}

int main()
{
    prec();

    scanf("%d %s", &n, s);

    n--;
    int one=0;
    for(int i=0; i<n; i++) {
        int x = s[i]-'0', y = s[i+1]-'0';
        a[i]=abs(x-y);
        if(a[i]==1) one=1;
    }

    for(int i=0; i<n; i++) if(a[i]==2) a[i]=one^1;

    int ans = 0;
    for(int i=0; i<n; i++) {
        ans ^= cmb(n-1, i) & a[i];
    }

    if(!one && ans) ans=2;

    cout << ans << endl;
}
