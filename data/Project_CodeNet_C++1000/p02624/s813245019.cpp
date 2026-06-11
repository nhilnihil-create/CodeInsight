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
    int n ;
    cin >> n ;
    ll tot = 0 ;
    for(int i = 1; i <= n; i++){
        ll f = n/i ;
        tot += i*(1+f)*f/2 ;
    } 
    cout << tot << endl ;
}
