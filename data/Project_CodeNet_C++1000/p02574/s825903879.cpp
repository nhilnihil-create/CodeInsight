#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define F first
#define S second
#define mod 1000000007
#define pb push_back
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REV(i,a,n) for(int i=a;i>=n;i--)
#define all(a) a.begin(),a.end()
const int NUM = 2e5 + 5;
const int N = 1e6 + 2;
int primes[N];
map<int,int> mp;
void sieve(){
    FOR(i,0,N)
        primes[i] = i;
    FOR(i,2,N)
        if(primes[i] == i)
            for(int j = i+i; j < N; j += i)
                primes[j] = min(primes[j],primes[i]);
}
void pf(int n){
    while(n != 1)
    {
        int d = primes[n];
        mp[d]++;
        while(n % d == 0)
            n /= d;
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int num_tests=1; 
    //cin >> num_tests;
    while(num_tests-->0){
        sieve();
        int n; cin >> n;
        vector<int> a(n);
        FOR(i,0,n) cin >> a[i];
        int gcd = 0;
        for(auto x:a)
            gcd = __gcd(x,gcd);
        for(auto x:a)
            pf(x);
        bool ok = 1;
        for(auto x:mp)
            if(x.S >= 2)
            {
                ok = 0; break;
            }
        if(ok)
            cout << "pairwise coprime";
        else if(gcd == 1) cout << "setwise coprime";
        else cout << "not coprime";
    }    
}