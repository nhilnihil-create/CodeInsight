#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    
    long long int i, N;
    long long int ans = 0;
    cin >> N;
    
    for (i = 1; i <= N; i++){
        
        long long int x = N / i;
        ans += i * x * (x + 1) / 2;
    }
    
    cout << ans << "\n";

    return 0;
}
