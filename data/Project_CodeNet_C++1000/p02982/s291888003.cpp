#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    double n, d; cin >> n >> d;
    vector< vector<double> > v(n, vector<double>(d));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < d; ++j){
            cin >> v[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            double val = 0;
            for(int k = 0; k < d; ++k){
                val += (abs(v[i][k] - v[j][k]) * abs(v[i][k] - v[j][k]));
            }
            val = sqrt(val);
            if(val == (ll)val) ++ans;
        }
    }    
    return cout << ans << '\n', 0;
}