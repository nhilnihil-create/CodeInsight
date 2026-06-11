#include <iostream>
#include <string>
using namespace std;

int main() {
    string x, y;
    cin >> x >> y;
    y[y.length() - 1] = 0;
    for (int i = 0; i < y.length(); i++) {
        if (y[i] == x[i]) {
            if (i == y.length() - 1){
                cout << "Yes";
            }else {
                continue;  
            }
        } else {
            cout << "No";
            break;
        }
    }
    
}