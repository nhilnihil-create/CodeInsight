#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int , int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 

int main() {
    int n, d ;
    cin >> n >> d ;
    d = d * 2 + 1 ;
    int ans ;
    if(n % d != 0){
        ans = n / d + 1 ;
    }
    else {
        ans = n / d ;
    }
    cout << ans << endl ;
}