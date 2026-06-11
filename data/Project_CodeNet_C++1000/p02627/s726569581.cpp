#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    
    char X;
    cin >> X;
    
    if (isupper(X)){
        cout << 'A' << "\n";
    } else {
        cout << 'a' << "\n";
    }

    return 0;
}

