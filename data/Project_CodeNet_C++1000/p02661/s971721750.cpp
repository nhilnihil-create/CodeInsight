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

int main(){
    ll n;
    cin >> n;
    vl ue,shita;
    rep(i,n){
        ll a,b;
        cin >> a >>b;
        shita.pb(a);
        ue.pb(b);
    }
    isort(ue);
    isort(shita);
    if(n%2==0){
        ll m=ue[n/2-1]+ue[n/2];
        ll mi=shita[n/2-1]+shita[n/2];
        kaku(m-mi+1);
    }
    else{
        ll m=ue[n/2];
        ll mi=shita[n/2];
        kaku(m-mi+1);
    }
}