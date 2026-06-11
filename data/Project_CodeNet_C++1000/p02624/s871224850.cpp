#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main(void){

    int n;
    cin >> n;

    ll ans  = 0;
    for(int i = 1; i <= n; ++i){
        ll x = n / i;
        ans += x * (x + 1) * i / 2;
    }

    cout << ans << "\n";

    return 0;
}
