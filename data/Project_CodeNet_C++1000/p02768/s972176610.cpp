#include<bits/stdc++.h>
using namespace std;

#define IOS             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define watch(x);       cout << "\n" <<  #x << " is: " << x << "\n";
#define ll              long long int
#define ff              first
#define ss              second
#define all(a)          a.begin(),a.end()
#define pb              push_back
#define nl              cout<<"\n"
#define gcd(a,b)        __gcd(a,b)
#define sq(a)           (a)*(a)
#define loop(i,a,b)     for (ll i = a; i <= b; i++)
#define rloop(i,a,b)    for (int i = a; i >= b; i--)
#define sz(a)           a.size()
#define mod             1000000007
#define PI              2*acos(0.0)


long long qexp(long long A, long long B) { // calculate (A ^ B) % M
    if (B == 0) return 1; //base case A^0 = 1
    long long half = qexp(A, B/2);
    half *= half%mod;
    half %= mod;
    if (B % 2 == 1) half *= A;  //Compensate the 'round down' of B/2 when B is odd
    return half % mod;
}
ll coefficient(ll n, ll k) { // Calculate nCk
    ll res = 1;
    k = min(k, n - k); // as C(n, k) = C(n, n - k)
    for (ll i = 0; i < k; i++) {
        res = res * qexp(i + 1, mod - 2) % mod * (n - i) % mod;
    }
    return res;
}
int main()
{
    IOS
    int T=1;
    //cin>>T;
    while(T--)
    {
        ll n,a,b;
        cin>>n>>a>>b;
        cout<<((qexp(2,n)-coefficient(n,a)-coefficient(n,b)-1)%mod+mod)%mod;

    }
    return 0;
}
