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
    vector<int> vec (n) ;
    rep(i, n) cin >> vec[i] ;
    int ans = 0 ;
    for(int i = 1 ; i < n -1 ; i++){
        int a = vec[i-1] ;
        int b = vec[i] ;
        int c = vec[i + 1] ;
        if((a > b && c < b) || (a < b && c > b)){
            ans++ ;
        }
    }
    cout << ans << endl ;
}