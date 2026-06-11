/*
        karmany evadhikaras te
        ma phalesu kadacana 
        ma karma-phala-hetur bhur
        ma re sango'stv akarmani (B.G.-2.47)
 
Translation:
        Lord Krsna to Arjuna.
You have a right to perform your prescribed duty, 
but you are not entitled to the fruits of action. 
Never consider yourself the cause of the results of your activities, 
and never be attached to not doing your duty.    
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long
const int N = 4005;
const ll mod = 1e9+7;
#define ld long double
#define PI 3.14159265358979323846
const int INF = 10000000;

void flash()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
}

//3. Structure or classes
//3. Ends here

//1. Data structures declaration here
//1. Ends here

//2. Extra Functions here
int power(long long a, long long b) {
    int c = 1;
    while (b) {
        if (b & 1) c = c * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return c;
}

int comb(int a,int b){
    long long x = 1, y = 1;
    for (int i = 0; i < b; i++) {
        x = x * (a - i) % mod;
        y = y * (i + 1) % mod;
    }
    return x * power(y, mod - 2) % mod;
}
//2. Ends here


void solve();
int32_t main()
{
    flash();
    int t;
    t = 1;
    //cin>>t;
    while(t--){
        solve();
        //cout<<"\n";
    }
    return 0;
}

void solve()
{
    int n,a,b;
    cin>>n>>a>>b;

    int res=1;
    int base=2;

    int n1=n;

    n1%=mod;

    while(n1>0){
        if(n1&1){
            res=(res*base)%mod;
        }
        base = (base * base)%mod;
        n1>>=1;
    }

    res%=mod;

    //cout<<res<<" "<<comb(n,a)<<" "<<comb(n,b)<<"\n";

    int ans = res-comb(n,a)-comb(n,b)-1;

    cout<<(ans%mod+mod)%mod<<"\n";
    return;
}
// how r u bro