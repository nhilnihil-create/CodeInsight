#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main(void){


    int n, d;
    cin >> n >> d;

    int ans = 0;
    for(int i = 0; i < n; ++i){
        ll x, y;
        cin >> x >> y;

        long double D = sqrt(x*x + y*y);
        if(D <= double(d)){
            ans ++;
        }
    }

    cout << ans << "\n";

    return 0;
}