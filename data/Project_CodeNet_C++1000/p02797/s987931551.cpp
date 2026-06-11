#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int N , K , S;
    cin >> N >> K >> S;
    for (int i = 1; i <= K; i++){
        cout << S << " ";
    }
    int T = N - K;
    for (int i = 1; i <= T; i++){
        if (S == 1000000000){
            cout << S - 1 << " ";
        }
        else{
            cout << S + 1 << " ";
        }
    }
}