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
    ll N, K;
    cin >> N >> K;

    ll count = 0;
    REP(i,N){
        ll h;
        cin >> h;
        if( h < K ){

        }else{
            count++;
        }
    }

    cout << count << endl;
}
