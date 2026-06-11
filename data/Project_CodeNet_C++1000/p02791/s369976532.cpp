#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 
int main(){
    int n ;
    cin >> n ;
    int bd = 200005;
    int ans = 0; 
    rep(i, n){
        int p ;
        cin >> p ;
        if(p < bd){
            ans++ ;
            bd = p ;
        } 
    }
    cout << ans << endl ;

} 