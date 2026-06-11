#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <math.h>
#include <string>
#include <sstream>
#include <stack>
#define inf 1e9+7
#define pb push_back
#define make make_pair
#define kaku(a) cout << a << endl;
 
using namespace std;
 
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define PI 3.14159265359
long long gcd(long long a,long long b){ return b==0?a:gcd(b,a%b);}
long long lcm(long long a,long long b){ return a/gcd(a,b)*b;}

int main(void){
    ll n;
    cin >> n;
    ll a[n+10][n+10];
    rep(i,n){
        rep(j,n-1) {
            cin >> a[i][j];a[i][j]--;
        }
    }
    bool OK=true;
    ll ans=0;
    bool d[n];//その日試合をしているか
    ll next[n];
    rep(i,n) next[i]=0;
    while(OK){
        OK=false;
        ans++;
        rep(i,n) d[i]=false;
        for(ll i=0;i<n;i++){
            if(next[i]!=n-1){
                    ll aite=a[i][next[i]];
                    if(!d[i] && !d[aite] && i==a[aite][next[aite]]){
                        d[i]=true;
                        d[aite]=true;
                        next[i]++;
                        next[aite]++;
                        OK=true;
                    }
            }
        }
    }
    ll loop=true;
    for(ll j=0;j<n;j++) if(next[j]!=n-1) loop=false;
    if(loop) cout << ans-1 << endl;
    else cout << -1 << endl;
}

