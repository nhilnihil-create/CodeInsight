#include <bits/stdc++.h>
using namespace std;

int main(void){
    int rate, kyu;
    cin >> rate;
    
    for(int r = 600, k = 8;k > 0;r += 200, k -= 1) {
        if (rate < r) {
            kyu = k;
            break;
        }
    }
    
    cout << kyu << endl;
    return 0;    
}