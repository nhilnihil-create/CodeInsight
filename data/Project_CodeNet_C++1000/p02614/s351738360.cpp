#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define rep(i,n) for(int i = 0;i < n;i++)
#define NIL = -1;
#define all(x) x.begin(),x.end()
const ll INF = 1e9;
const ll mod = 1e9 + 7;

int digit(ll x) {
    if (x / 10 == 0) return 1;
    return digit(x / 10) + 1;
}

ll gcd(long long a,long long b) {
    if (a < b) swap(a,b);
    if (b == 0) return a;
    
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    return ((a * b == 0)) ? 0 : (a / gcd(a,b) * b);
}

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};


//////////////////////////////////////////////////////////////////////////////////////

int main(){
    int h, w, k;
    int ans = 0;
    cin >> h >> w >> k;
    vector<vector<char>> c(h, vector<char>(w));
    for(int i = 0;i < h;i++){
        for (int j = 0;j < w;j++){
            cin >> c[i][j];
        }
    }

    for (int bith = 0;bith < (1 << h);bith++){
        for (int bitw = 0;bitw < (1 << w);bitw++){
            int count = 0;
            for (int i = 0;i < h;i++){
                for (int j = 0;j < w;j++){
                    if (bith & (1 << i)){
                        continue;
                    }

                    if (bitw & (1 << j)){
                        continue;
                    }

                    if (c[i][j] == '#'){
                        count++;
                    }
                }
            }
                    if (count == k){
                        ans++;
                    }
        }
    }
    cout << ans << endl;
}