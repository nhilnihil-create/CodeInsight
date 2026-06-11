#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(long i = 0; i < (n); i++)
using namespace std;
using P = pair<long, long>;
long mod = (long) 1e9 + 7;
long ans[2001][2001] = {};

int main(){
    
    long n;
    cin >> n;
    set<P> s;
    
    rep(i,n){
        long x;
        cin >> x;
        s.emplace(P((-1 * x),i));
    }
    
    long x = 0;
    
    for(auto i:s){
        
        ans[x + 1][0] = ans[x][0] + i.first * -1 * abs(i.second - x);
        ans[0][x + 1] = ans[0][x] + i.first * -1 * abs(i.second + x + 1 - n);
        rep(j,x){
            ans[x - j][1 + j] = max(ans[x - j - 1][1 + j] + i.first * -1 * abs(i.second - x + j + 1),
                                    ans[x - j][j] + i.first * -1 * abs(i.second + j + 1 - n));
        }
        x++;
    }
    
    long res = 0;
    rep(i,n + 1){
        res = max(res, ans[n - i][i]);
    }
    
    cout << res << "\n";
    
    return 0;
}


