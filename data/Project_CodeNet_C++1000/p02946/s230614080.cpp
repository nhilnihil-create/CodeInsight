#include <iostream>
using namespace std;
typedef long long ll;

int main() {    
    int k,x;
    cin >> k >> x;

    if(x - (k-1) < -1000000) {
        for(int i = -1000000; i < x + k; i++) {
            if(i != -1000000) cout << " ";
            cout << i;
        }
        cout << endl;
    }
    else if(1000000 < x + k -1) {
        for(int i = x-(k-1); i < 1000001; i++) {
            if(i != x -(k-1)) cout << " ";
            cout << i;
        }
        cout << endl;
    }
    else {
        for(int i = x - (k-1); i < x + k; i++) {
            if(i != x - (k-1)) cout << " ";
            cout << i;
        }
        cout << endl;
    }
    return 0;
}
