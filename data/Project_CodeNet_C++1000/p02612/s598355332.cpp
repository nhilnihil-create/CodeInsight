#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(){

    int N, ans;
    cin >> N;
    
    if (N % 1000 == 0){
        ans = 0;
    } else {
        ans = 1000 - (N % 1000);
    }

    cout << ans << "\n";

    return 0;
}

