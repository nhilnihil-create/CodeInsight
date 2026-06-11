#include <iostream>
#include <string>
using namespace std;

//分布にすることが本質である
//前から決め打つ
//個数の分布管理に帰着させてみよ
//複数おける場合があるとき, 分布にすることで本質が見えるかも？

int N, A[1<<18], C[3];
long long sum = 1;
long long mod = 1e9 + 7;
int main(){
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    
    for (int i = 1; i <= N; i++){
        long long cnt = 0, id = -1;
        
        if (A[i] == C[0]){cnt++, id = 0;}
        if (A[i] == C[1]){cnt++, id = 1;}
        if (A[i] == C[2]){cnt++, id = 2;}
        
        if (id == -1){
            cout << 0 << endl;
            return 0;
        }
        sum *= cnt;
        C[id]++;
        sum %= mod;
    }
    cout << sum << endl;
    return 0;
}
 