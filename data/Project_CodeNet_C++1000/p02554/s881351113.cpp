#include <iostream>
using namespace std;
typedef long long ll;

int main(void){
    int n;
    int MOD = 1e9+7;
    ll result, temp_10, temp_9, temp_8;
    cin >> n;
    
    temp_10 = 1;
    temp_9  = 1;
    temp_8  = 1;
    for (int i = 0; i < n; i++){
        temp_10 = temp_10 * 10 % MOD;
        temp_9  = temp_9 * 9 % MOD;
        temp_8  = temp_8 * 8 % MOD;
    }
    
    result = (temp_10 - 2 * temp_9 + temp_8) % MOD;
    if (result < 0) result += MOD;
    
    cout << result << endl;
}
