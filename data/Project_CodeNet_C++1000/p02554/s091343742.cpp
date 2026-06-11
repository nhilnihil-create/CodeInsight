#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tt int tc; cin>>tc; while(tc--)
#define nl cout<<"\n";
#define sp cout<<" ";
#define rep(i, a, b) for(long long i=a; i<b; i++)

const int INF = 1e9 + 7;
long long MOD = 1e9 + 7;
double PI = 4*atan(1);


ll poow( ll n, ll e)
{
    ll ans= 1;

    for(int i=1; i<=e; i++)
    {
        ans*= n;
        ans%= MOD;
    }
    return ans%MOD;
}

int main()
{
    optimize();

    long long n;

    cin>> n;

    ll res= poow(10LL, n ) % MOD;
    res-= (2 * (poow( 9LL, n)- MOD) );
    res%= MOD;
    res+= ( poow (8LL, n));   ////subtracting the overlap to prevent double counting [minus* minus= plus]
    res%= MOD;
    cout << res;
    nl;

    return 0;
}



//∣AUB∣ = ∣A∣ + ∣B∣ − ∣A∩B∣ //subtracting the overlap to prevent double counting
//
//A = Set of sequences that does not contain 0
//
//B = Set of sequences that does not contain 9
//
//n(A) = n(B) = pow(9,n)
//
//n(A intersection B) = pow(8,n)


