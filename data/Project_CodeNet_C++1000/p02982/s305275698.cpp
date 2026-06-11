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
    int n, d ; 
    cin >> n >> d ;
    vector<vector<double>> za (d) ;
    rep(i, n){
        rep(j, d){
            double x ;
            cin >> x ;
            za[j].push_back(x) ;
        }
    }
    int ans = 0;
    for(int i = 0 ; i < n - 1; i++ ){
        for(int j = i + 1 ; j < n ; j++){
            double tot = 0 ;
            rep(p, d){
                tot += (pow(za[p][i] - za[p][j], 2)) ;
            }
            tot = sqrt(tot) ;
            int k = int(tot) ;
            if(k == tot){
                ans++ ;
            }
        }
    }
    cout << ans << endl ;
}