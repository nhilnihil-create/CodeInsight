#include "bits/stdc++.h"
using namespace std;
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int inf = 1e9+7;
const int N = 1e6+9;

int main() {
    ios_base::sync_with_stdio(0);
    ll a,b,x;
    cin>>x;
    ll n=100;
    for(ll i=1;;++i) {
        ll p = n/100;
        n += p;
        if(n>=x) {
            cout<<i<<endl;
            return 0;
        }
    }   
    return 0;
}