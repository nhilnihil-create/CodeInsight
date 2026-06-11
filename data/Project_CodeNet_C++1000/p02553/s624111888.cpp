#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <numeric>
#include <queue>
#include <cstdio>
#include <cstring>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<n;++i)
#define mrep(i,n) for(ll i=n;i>=0;--i)
#define all(a) (a).begin(),(a).end()
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vb vector<bool>
#define vvb vector<vector<bool> >
#define pl pair<ll,ll>
#define inf 1001001001001001000
#define mod 1000000007
//#define mod 998244353
#define pi 3.1415926535
using namespace std;
struct __INIT{
    __INIT(){
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout<<fixed<<setprecision(15);
    }
}__init;

int main(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll t1 = a*c;
    ll t2 = a*d;
    ll t3 = b*c;
    ll t4 = b*d;
    cout<<(ll)(max({t1,t2,t3,t4}))<<endl;
    return 0;
}