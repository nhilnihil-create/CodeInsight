#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n, x; cin >> n >> x;
    V<int> l(n);
    for(int i = 0; i < n; i++) cin >> l[i];

    int ans = 1;
    int d = 0;
    for(int i = 0; i < n; i++){
        d = d + l[i];
        if(d <= x){
            ans++;
        }else{
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
