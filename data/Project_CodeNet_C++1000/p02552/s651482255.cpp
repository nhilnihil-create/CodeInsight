#include <iostream>

using namespace std;

int main() {
    int x;
    ios::sync_with_stdio(false);
    
    cin >> x;

    if(x == 0) cout << "1";
    else if(x == 1) cout << "0";

    return 0;
}