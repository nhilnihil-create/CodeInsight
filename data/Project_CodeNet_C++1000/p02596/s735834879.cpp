#include <iostream>
using namespace std;

int main() {
    long long K,i, X=7, ans=-1;
    cin >> K;
    for(i=1; i<=K; i++){
        if(X%K == 0){
            ans = i;
            break;
        }
        X = (10*X + 7)%K;
    }
    cout << ans << endl;
}