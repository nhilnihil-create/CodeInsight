#include <bits/stdc++.h>
using namespace std;
#define bye ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define mp make_pair
#define Mod (ll)(1e9+7)
#define matrix vector<vector<ll> >
#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())
#define double long double
#define PI acos(-1)

ll n,m,k;
ll a[100100],ans,temp;

ll fastpow(ll n,ll po){
    if(!po)
        return 1;
    ll mul = fastpow(n,po/2);
    mul %= Mod;
    mul*=mul;
    mul%=Mod;
    if(po&1)
        mul*=n;
    mul%=Mod;
    return mul;
}

int main()
{
    bye;
    cin >> n >> k;
    for(int i=k;i>=1;i--){
        ll ans = fastpow(k/i,n);
        for(int j=i+i;j<=k;j+=i){
            ans-=a[j];
            ans+=Mod;
            ans%=Mod;
        }
        a[i] = ans;
        temp+=(i*ans)%Mod;
        temp%=Mod;
    }
    cout << temp << "\n";
    return 0;
}
