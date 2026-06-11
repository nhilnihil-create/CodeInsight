#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    int ans[10][10];
    rep(i, 10){
        rep(j, 10){
            ans[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; i++){
        int t = i;
        int l = i%10;
        while (t/10 != 0){
            t /= 10;
        }
        ans[t][l]++;
    }

    ll ANS = 0;
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            ANS += ans[i][j] * ans[j][i];
        }
    }

    cout << ANS << endl;

    return 0;
}