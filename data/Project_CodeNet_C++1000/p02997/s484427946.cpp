#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    int n, k; cin >> n >> k;
    int cpy = k;
    int limit = ((n - 1)*(n - 2))/2;
    if(k > limit){
        cout << "-1\n";
    }else{
        bool matrix[n][n]; memset(matrix, 1, sizeof(matrix));
        for(int i = n - 1; ~i; --i){
            for(int j = n - 1; j > i; --j){
                if(k){
                    --k;
                    matrix[i][j] &= 0;
                    //cout << i << ' ' << j << '\n';
                }
            }
        }
        cout << (n*(n - 1))/2 - cpy << '\n';
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                if(matrix[i][j]) cout << i + 1 <<  ' ' << j + 1 << '\n';
            }
        }
    }
    return 0;  
}