#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 

int main(){
    int n ;
    cin >> n ;
    vector<vector<P>> vec (n) ;
    rep(i, n){
        int a ;
        cin >> a ;
        rep(j, a){
            int x, y ;
            cin >> x >> y ;
            x-- ;
            vec[i].push_back(P(x, y)) ;
        }
    }
    int num = 0 ;
    rep(i, 1 << n) {
        vector<int> ans (n, -1) ;
        int res = 0 ;
        bool can = true ;
        rep(j, n){
            if(i >> j & 1){
                rep(k, vec[j].size()){
                    int fi = vec[j][k].first ;
                    int se = vec[j][k].second ; 
                    if(ans[fi] != se && ans[fi] != -1){
                        can = false ;
                    }
                    else {
                        ans[fi] = se ; 
                    }
                }
                res++ ;
            }
        }
        if(can){
                    rep(j, n){
            if((i >> j & 1) != ans[j] && ans[j] != -1){
                res = 0 ;
            }
        }
        num = max(num, res) ;
        }

    }
    cout << num << endl ;
} 