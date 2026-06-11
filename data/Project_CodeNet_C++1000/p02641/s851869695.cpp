#include <iostream>
#include <string>
using namespace std;

#define N_MAX 100

int X; // 1~100
int N; // 0~100
int p[N_MAX]; //1~100

void input(){
    cin >> X >> N;
    for (int i=0;i<N;i++){
        cin >> p[i];
    }
}

void solve(){
    // pに含まれない整数のうち、最もXに近いものを答えよ。
    // 複数存在する場合は小さい方を答えよ。
    int ans = X;
    int deff = 100;
    for (int i=0;i<102;i++){
        for (int j=0;j<N;j++){
            if (p[j]==i) break;
            if (j==N-1) {
                if (deff>abs(X-i)){
                    deff = abs(X-i);
                    ans = i;
                }
            }
        }
    }
    cout << ans << endl;
}

int main(){
    input();
    solve();
    return 0;
}