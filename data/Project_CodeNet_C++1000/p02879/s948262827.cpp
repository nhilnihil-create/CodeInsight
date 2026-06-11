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

    int A, B;
    cin >> A >> B;

    if( A >= 10 || B >= 10 ){
        cout << -1 << endl;
    }else{
       cout << A*B << endl;
    }
}
