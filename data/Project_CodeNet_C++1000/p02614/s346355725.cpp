#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define INF 999999999
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

using llong = long long;
using namespace std;

int main(){
    int h,w,k,ans=0;
    char c[10][10];
    cin >> h >> w >> k;
    rep(i,h) cin >> c[i];
    
    for(int bith=0;bith < (1<<h); bith++){
        for(int bitw=0;bitw < (1<<w);bitw++){
            int brack=0;
            rep(i,h) if(((bith>>i) & 1) == 0){
                rep(j,w) if(((bitw>>j) & 1) == 0){
                    if(c[i][j] == '#') brack++;
                }
            }
            if(brack == k) ans++;
        }
    }
    
    cout << ans << endl;
    
}