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

typedef pair<ll,ll> Pair;

ll n,k;

void solve(){
    if(k>(n-1)*(n-2)/2) {
        kaku(-1);
    }
    else{
        ll edge=(n-1)*(n-2)/2-k;
        kaku(edge+(n-1));
        for(ll i=2;i<=n;i++) cout << 1 << " " << i << endl;
        for(ll i=2;i<=n-1 && edge;i++){
            for(ll j=i+1;j<=n && edge;j++){
                cout << i << " " << j << endl;
                edge--;
            }
        }
    }
}

int main(){
    cin >> n >> k;
    solve();
    return 0;
}


