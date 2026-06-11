#include <iostream>
#include <vector> 
#include <cmath>
using namespace std;

#define int long long

signed main() {
    vector<int> x(5);
    for(int i = 0; i < 5; i++) cin >> x[i];

    for(int i = 0; i < 5; i++) {
        if(x[i] == 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}