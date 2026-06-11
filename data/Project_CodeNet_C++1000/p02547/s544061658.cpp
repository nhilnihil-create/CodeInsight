#include <iostream>

using namespace std;

int main() {
    int x, a, b, count = 0;
    bool row = false, ans = false;
    
    cin >> x;
    
    for(int i = 0; i < x; i++) {
        cin >> a >> b;
        if(a == b) {
            count++;
            if(!row) row = true;
        }
        else {
            row = false;
            count = 0;
        }
        
        if(count == 3) ans = true;
    }
    
    cout << (ans?"Yes":"No") << endl;
    

    return 0;
}