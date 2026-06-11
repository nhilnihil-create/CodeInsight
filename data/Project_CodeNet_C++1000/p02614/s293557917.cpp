#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int h,w,k;
    cin >> h >> w >> k;
    bool table[6][6];
    bool tmp[6][6];
    rep(i,6){
        rep(j,6){
            table[i][j] = false;
        }
    }
    char c;
    rep(i,h){
        rep(j,w){
            cin >> c;
            if(c == '.')
                table[i][j] = false;
            else
                table[i][j] = true;
        }
    }
    
    int ans = 0;

    rep(i,1 << h){
        rep(j,1 << w){
            rep(y,h){
                rep(x,w){
                    tmp[y][x] = table[y][x];
                }
            }

            rep(k,h){
                if(i & (1 << k)){
                    rep(l,w){
                        tmp[k][l] = false;
                    }
                }
            }

            rep(k,w){
                if(j & (1 << k)){
                    rep(l,h){
                        tmp[l][k] = false;
                    }
                }
            }

            int cnt = 0;
            rep(y,h){
                rep(x,w){
                    if(tmp[y][x])cnt++;
                }
            }
            if(cnt == k)ans++;
        }
    }

    cout << ans << endl;
    return 0;
}