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
    ll x ;
    cin >> x ;
    if(x >= 0){
        rep(i, 1000){
            rep(j,1000){
                if(pow((double)i, 5) - pow((double)j, 5) == x){
                    cout << i << " " << j << endl ; 
                    return 0 ;
                }
            }
        }
        rep(i, 1000){
            rep(j, 1000){
                if(pow((double)i, 5) + pow((double)j, 5) == x){
                    cout << i << " " << -j << endl ;
                    return 0 ;
                }
            }
        }
    }
    else {
        rep(i, 1000){
            rep(j,1000){
                if(pow((double)i, 5) - pow((double)j, 5) == x){
                    cout << i << " " << j << endl ; 
                    return 0 ;
                }
            }
        }
        rep(i, 1000){
            rep(j, 1000){
                if(-(pow((double)i, 5) + pow((double)j, 5)) == x){
                    cout << -i << " " << j << endl ;
                    return 0 ;
                }
            }
        }
    }
}  