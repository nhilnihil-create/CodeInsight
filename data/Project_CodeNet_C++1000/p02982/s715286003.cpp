#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()


int main(){
    int N, D;
    cin >> N >> D;
    vector<vector<int>> X(N,vector<int>(D));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < D; j++) cin >> X[i][j];
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            if(i == j) continue;
            ll dist = 0;
            for(int k = 0; k < D; k++){
                dist += (X[i][k] - X[j][k]) * (X[i][k] - X[j][k]);
            }
            bool flag = false;
            for(int k = 1; k <= dist; k++){
                if(k * k == dist) flag = true;
            }
            if(flag) ans++;
        }
    }
    cout << ans << endl;
}
