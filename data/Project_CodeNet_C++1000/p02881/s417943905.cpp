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
    double  n ;
    cin >> n;
    int k = int(sqrt(n)) ;
    ll nn = n;
    ll ans = n - 1;
    for(int i = 2; i <= k ; i++ ){
        ll yok = INF ;
        ll tate = INF ;
        if(nn % i == 0){
            yok = i ;
            tate = nn / i ;
        }
        if((yok + tate - 2) < ans){
            ans = yok + tate - 2 ;
        }
    }
    cout << ans << endl ;
}