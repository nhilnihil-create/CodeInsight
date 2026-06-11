#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if(a == b){
        cout << 0 << endl;
        return 0;
    }
    int k = abs(a - b) / 2;
    if(a < b){
        if(b - k == a + k){
            cout << b-k << endl;
            return 0;
        }else{
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }else{
        if(b + k == a - k){
            cout << b+k << endl;
            return 0;
        }else{
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
}