#include <iostream>
#include <string>
using namespace std;

#define N_MAX 100

int64_t A; // ~10^15
int Bx100;
string str_B; //文字列でとって、小数点を取り除いて、int型にぶちこむ。

void input(){
    cin >> A >> str_B;
    str_B.erase(1,1);
    Bx100 = stoi(str_B);
}

void solve(){
    // pに含まれない整数のうち、最もXに近いものを答えよ。
    // 複数存在する場合は小さい方を答えよ。
    int64_t ans;
    ans = A*Bx100/100;
    cout << ans << endl;
}

int main(){
    input();
    solve();
    return 0;
}