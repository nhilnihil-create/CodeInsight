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

    ll N, X;
    cin >> N >> X;

    ll count = 1;
    ll p = 0;
    REP(i, N){ 
       ll l;
       cin >> l;
       p += l;
       if( p <= X ){
         count++;
       }else{
          break;
       }
    }

    cout << count << endl;
}
