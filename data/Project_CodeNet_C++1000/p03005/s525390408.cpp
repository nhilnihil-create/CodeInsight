#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){
    int N, K; cin >> N >> K;

    if(K == 1){
        cout << 0 << endl;
    } else {
        cout << N - K << endl;
    }
}