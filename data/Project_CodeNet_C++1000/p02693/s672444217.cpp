#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long double ld;
typedef long long ll;
const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;


int main() {
    int k; cin >> k;
    int a, b; cin >> a >> b;

    for(int i = a; i <= b; i++){
        if(i % k == 0){
            cout << "OK" << endl;
            return 0;
        }
    }
    cout << "NG" << endl;

    return 0;
}
