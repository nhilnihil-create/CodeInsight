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
    string s;
    cin >> s;
    ll n=s.size();
    ll d0[n],d1[n];
    d0[0]=min((s[0]-'0'),1+10-(s[0]-'0'));
    d1[0]=min(1+9-(s[0]-'0'),s[0]-'0'+1);

    for(ll i=1;i<n-1;i++){
        d0[i]=min(d0[i-1]+(s[i]-'0'),d1[i-1]+10-(s[i]-'0'));
        d1[i]=min(d1[i-1]+9-(s[i]-'0'),d0[i-1]+1+(s[i]-'0'));
    }
    if(n>=2){
        d0[n-1]=min(d0[n-2]+(s[n-1]-'0'),d1[n-2]+10-(s[n-1]-'0'));
    }
    kaku(d0[n-1]);
}

int main(){
    solve();
}