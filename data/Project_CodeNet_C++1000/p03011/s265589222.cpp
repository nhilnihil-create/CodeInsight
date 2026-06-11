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

    vector<int> a(3);

    cin >> a[0] >> a[1] >> a[2];

    sort(a.begin(), a.end());

    cout << a[0]+a[1] << endl;
}
