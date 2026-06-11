#include <bits/stdc++.h>
#define ll long long int
#define rep(i,a,b) for(long long i=a; i<b; i+=1)
#define repr(i,a,b) for(long long i=a; i<=b; i+=1)
#define vec vector<ll>
#define map map<char,int>
#define repa(p,A) for(auto p:A)
#define pb push_back
#define sort(a) sort(a.begin(),a.end())
#define reverse(a) reverse(a.begin(),a.end())
const double PI=acos(-1);
using namespace std;

int main( ) {
    ll A;
    double B;
    cin>>A>>B;
    ll C=B*100+0.5;
    ll D=A*C;
    ll E=D/100;
    printf("%lld\n",E);
    }
