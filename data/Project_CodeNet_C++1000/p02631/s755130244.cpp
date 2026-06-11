#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    
    int i, x = 0, N, a_max, keta = 0;
    cin >> N;
    
    vector<int> a(N, 0);
    for (i = 0; i < N; i++){
        cin >> a[i];
        x = x ^ a[i];
    }
    
    for (i = 0; i < N; i++){
        
        cout << (a[i] ^ x) << ' ';
    }
    
    cout << "\n";

    return 0;
}


