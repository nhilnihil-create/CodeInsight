#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {

    int N, D;
    cin >> N >> D;
    int X[N][D];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < D; j++){
            cin >> X[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            if(i==j){
                continue;
            }

            int diff2sum = 0;
            for(int k = 0; k < D; k++){
                diff2sum += ((X[i][k] - X[j][k]) * (X[i][k] - X[j][k]));
            }
            double diff = sqrt(diff2sum);

            if(ceil(diff) == floor(diff)){
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}