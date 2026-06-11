#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
vector<int> mx = {1,0,-1,0} ;
vector<int> my = {0, 1, 0, -1} ;


int main () {
    ll h ;
    cin >> h ;
    double num = 0 ;
    while(h > 1){
        h /= 2 ;
        num++ ;
    }
    num++ ;
    ll ans = ll(pow(2, num)) - 1 ;
    cout << ans << endl ;
}