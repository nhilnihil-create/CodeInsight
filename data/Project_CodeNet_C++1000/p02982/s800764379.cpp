#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,D;
    cin >> N >> D;
    vector<vector<int>> X(N,vector<int>(D));
    for ( int i = 0; i < N; ++i){
        for ( int j = 0; j < D; ++j){
            cin >> X[i][j];
        }
    }
    
    int count = 0;
    for ( int i = 0; i < N-1; ++i){
        for ( int j = i+1; j < N; ++j){
            int dis = 0;
            for ( int k = 0; k < D; ++k){
                dis = dis + ( X[i][k] - X[j][k] ) *  ( X[i][k] - X[j][k] );
            }
            bool flg = false;
            for ( int x = 1; x < 1000; ++x){
                if ( dis == x * x ) flg = true;
            }
            if ( flg ) ++ count;
        }
    }
    
    cout << count << endl;
    
    return 0;
}