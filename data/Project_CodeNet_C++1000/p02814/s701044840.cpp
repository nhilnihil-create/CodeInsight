//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define mod (ll)(1e9+7)
#define FIX(a) ((a)%mod+mod)%mod
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define fi first
#define se second
#define pb push_back
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
ll gcd(ll a, ll b ){
    ll r, tmp;
    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }
    r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
ll lcm(ll a, ll b ){
    if(a==0||b==0) return 0;
    return ((a/gcd(a,b))*b);
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    vll a(n),b(n);
    ll bgcd=1;
    REP(i,n){
        cin >> a[i];
        b[i]=a[i]/2;
        bgcd = lcm(bgcd,b[i]);
    }
    REP(i,n){
        if((bgcd/b[i])%2==0LL){
            cout << 0 << endl;
            return 0;
        }
    }
    if(bgcd>m){
        cout << 0 << endl;
    }else{
        ll ans = (m-bgcd)/(2*bgcd)+1;
        cout << ans << endl;
    }
    return 0;
}