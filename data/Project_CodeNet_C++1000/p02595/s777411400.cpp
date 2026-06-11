#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    
    long long int i, x, y, N, D, count;
    
    cin >> N >> D;
    count = 0;
    
    for (i = 0; i < N; i++){
        
        cin >> x >> y;
        if (x * x + y * y <= D * D) count++;
    }
    
    cout << count << "\n";

    return 0;
}

