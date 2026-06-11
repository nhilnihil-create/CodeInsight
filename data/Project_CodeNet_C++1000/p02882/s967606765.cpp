#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

int main (){
    double a, b, x ;
    cin >> a >> b >> x ;
    if(a*a*b/2 <= x){
        double ans = atan(2*(a*a*b - x)/(a*a*a)) ;
        ans = ans * 180 / PI ;
        cout << fixed << setprecision(10) ;
        cout << ans << endl ;
    }
    else {
        double ans = atan(a*b*b/(2*x)) ;
        ans = ans * 180 / PI ;
        cout << fixed << setprecision(10) ;
        cout << ans << endl ;
    }
}