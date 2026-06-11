#include <iostream>
using namespace std;
using ll = long long;
int main(void) {
    ll A,B,K; cin >> A >> B >> K;
    ll ans_A = 0, ans_B=0;
    if(A+B < K) {
        ans_A = 0; 
        ans_B = 0;
    }
    else if(A < K) {
        ans_A = 0; 
        ans_B = B - (K - A);
    }
    else {
        ans_A = A - K;
        ans_B = B;
    }
    cout << ans_A << " " << ans_B << endl;
}