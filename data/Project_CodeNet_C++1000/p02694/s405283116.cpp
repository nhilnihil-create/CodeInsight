#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    long long X = 100;
    long long A;
    cin >> A;
    int ans = 0;
    while(X < A){
        X += X/100;
        ans++;
    }
    cout << ans << endl;
}
