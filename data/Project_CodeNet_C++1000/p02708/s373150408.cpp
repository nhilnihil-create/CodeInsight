#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18

int main() {
    int n, k ;
    cin >> n >> k ; 
    ll min = 0 ;
    ll max = 0 ;
    ll ans = 0 ;
    rep(i, k - 1){
        min += i ;
        max += (n - i) ;
    }
    for(int i = k; i <= n + 1; i++){
        min += (i - 1) ;
        max += (n - i + 1) ;
        ans += max - min + 1 ;
        ans %= (1000000000 + 7) ;
    }
    cout << ans << endl ;
}  