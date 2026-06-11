#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1010000000000000017LL;
const ll MOD = 1000000007LL;

#define REP(i, n) for(ll i = 0 ; i < n; i++)

//#define DEBUG(fmt, ...)
#define DEBUG(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)

int main(){
    std::cout<<std::fixed<<std::setprecision(10);

    ll n;
    cin >> n;
    vector<ll> a(n);

    REP(i,n){
        cin >> a[i];
    }

    ll count = 0;
    for(int i = 1; i < n-1; i++ ){
       if( 
             (a[i-1] < a[i] && a[i] < a[i+1]) ||
             (a[i-1] > a[i] && a[i] > a[i+1])
         ){
          count++;
       }
    }

    cout << count << endl;
}
