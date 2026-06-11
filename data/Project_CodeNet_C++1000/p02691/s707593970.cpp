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
#define ll long long

using namespace std;


#define rep(i,n) for(ll i=0;i<n;i++)
#define PI 3.14159265359
long long gcd(long long a,long long b){ return b==0?a:gcd(b,a%b);}
long long lcm(long long a,long long b){ return a/gcd(a,b)*b;}

const ll inf =1000000007;
typedef pair<ll,ll> Pair;


typedef vector<ll> vl;

void solve(){
    ll n;
    cin >>n;
    map<ll,ll> mp;
    ll ans=0;
    rep(i,n){
        ll a;
        cin >>a;
        //足し算
        if(mp.find(i-a)!=mp.end()){
            ans+=mp[i-a];
        }
        if(mp.find(i+a)!=mp.end()){
            mp[i+a]++;
        }
        else{
            mp[i+a]=1;
        }
    }
    kaku(ans);
}


int main(){
    solve();
}