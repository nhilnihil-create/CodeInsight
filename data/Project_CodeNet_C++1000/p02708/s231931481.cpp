#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    long long N, K;
    cin >> N >> K;
    long long ans = 0;
    
    for(long long k = K; k <= N + 1 ; k++){
        ans += N*k - k*k + k + 1;
        ans %= 1000000000 + 7;
    }
    cout << ans << endl;
}
