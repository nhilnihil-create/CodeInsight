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
#include <deque>
#define pb push_back
#define make make_pair
#define kaku(a) cout << a << endl
#define isort(a) sort(a.begin(),a.end())

using namespace std;

#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define PI 3.14159265359
long long gcd(long long a,long long b){ return b==0?a:gcd(b,a%b);}
long long lcm(long long a,long long b){ return a/gcd(a,b)*b;}

typedef pair<ll,ll> Pair;
typedef vector<ll> vecll;
const ll inf =1000000007;

void solve(){
    ll n,k,c;
    cin >> n >> k >>c;
    string s;
    cin >> s;
    ll t=inf;
    ll mae[n];
    ll ushiro[n];
    rep(i,n){
        mae[i]=0;
        ushiro[i]=0;
    }

    //mae
    ll l=0;
    vecll L;
    for(ll i=0;i<n;i++){
        if(s[i]=='o' && t>=c){
            mae[i]=1;
            L.pb(i);
            t=0;
            l++;
            if(l==k) break;
        }
        else{
            t++;
        }
    }
    l=0;
    t=inf;
    vecll R;
    for(ll i=n-1;i>=0;i--){
        if(s[i]=='o' && t>=c ){
            ushiro[i]=1;
            R.pb(i);
            t=0;
            l++;
            if(l==k) break;
        }
        else{
            t++;
        }
    }
    reverse(R.begin(),R.end());
    for(ll i=0;i<k;i++){
        if(L[i]==R[i]){
            kaku(L[i]+1);
        }
    }

}

int main(){
    solve();
}