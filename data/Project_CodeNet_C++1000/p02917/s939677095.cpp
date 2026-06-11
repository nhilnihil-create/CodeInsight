#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double db;

#define ft first
#define sd second
#define flag bool fl=true

#define mod 1000000007
#define N 100001
#define MX 1000000001
#define MXX 1000000000000000001

#define pb push_back
#define For(i, a, b) for(int i=a;i<=b;i++)
#define T int t, qq=0; cin>>t; while(qq++<t)
#define fast ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define scarr(array, size) for(int i=0;i<size;i++) cin>>array[i]

#define deg(rad) (rad*180.0)/pi
#define pi acos(-1)
#define log(n) (int)log2(n)
#define logg(a)(b) log(b)/log(a)


/*
//----------useful_functions----------

long long extended_euclid(ll a, ll b, ll &x, ll &y){//ax+by=c
    if(b==0)
    {
        x=1, y=0;
        return a;
    }

    ll x1, y1;
    ll d=extended_euclid(b, a%b, x1, y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}
long long bigMod(ll a, ll b){//(a^b)%mod
    ll ans=1;
    while(b)
    {
        if(b%2==1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ans%mod;
}
long long modInverse(ll a, ll b){//a*x=1 mod b
    ll x, y;
    ll gcd=extended_euclid(a, b, x, y);

    if(gcd==1) return ((x%b)+b)%b;
    else return 1;
}
long long nCr(ll n, ll r){//n<=1e6
    //declare globally-> ll fact[1000001];
    fact[1]=1;
    for(ll i=2;i<1000001;i++)
        fact[i]=(i*fact[i-1])%mod;

    return (fact[n]*modInverse(fact[r], mod)*modInverse(fact[n-r], mod))%mod;
}
long long josephus(ll n, ll k){//k'th person is killed out of n in the circle
    if(n==1) return 1;
    else return (josephus(n-1, k)+k-1)%n+1;
}

vector<int> sieve(ll n){
    bool fl[n+1];
    vector<int> primes;
    for(int i=0;i<=n;i++) fl[i]=false;

    for(int i=3;i*i<=n;i+=2)
        for(int j=i+i;j<=n;j+=i)
            fl[j]=true;

    primes.pb(2);
    for(int i=3;i<=n;i+=2) if(!fl[i]) primes.pb(i);
    return primes;
}
*/

int main()
{
    int n;
    cin>>n;

    ll a[n-1];
    for(int i=0;i<n-1;i++) cin>>a[i];

    ll sum=a[0];
    for(int i=1;i<n-1;i++) sum+=min(a[i-1], a[i]);
    sum+=a[n-2];

    cout<<sum<<endl;
//        cout<<"Case "<<qq<<": ";
}
