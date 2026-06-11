#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    
    long long int X, K, D, rem, ans;
    cin >> X >> K >> D;
    
    X = abs(X);
    
    if (X / K >= D) {
        ans = X - K * D;

    } else if (K % 2 == 0){
        rem = X % (2 * D);
        ans = min(rem , 2 * D - rem);

    } else{
        rem = (X + D) % (2 * D);
        ans = min(rem, 2 * D - rem);

    }
        
    cout << ans << "\n";

    return 0;
}
