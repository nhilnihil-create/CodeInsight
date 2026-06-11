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
    int p, q, r ;
    cin >> p >> q >> r ;
    int res = p + q  ;
    res = min(res, q + r) ;
    res = min(res, r + p) ;
    cout << res << endl ;
}