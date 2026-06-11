#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

#define ll long long
#define D double
#define pb push_back
#define For(i,x,z) for(ll i=x;i<z;i++)
#define RFor(i,x,z) for(ll i=x;i>=z;i--)

template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return (POW(B,P/2))*(POW(B,P/2));}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/__gcd(a,b));}

int main()
{
    string s;
    cin>>s;
    ll p=1,n=0,cnt=0;
    map<ll,ll>m;
    m[0]++;
    RFor(i,s.size()-1,0)
    {
       n+=(s[i]-'0')*p;
       n%=2019;
       p*=10;
       p%=2019;
       //cout<<n<<endl;2
       cnt+=m[n];
       m[n]++;
    }
    cout<<cnt<<endl;
}
