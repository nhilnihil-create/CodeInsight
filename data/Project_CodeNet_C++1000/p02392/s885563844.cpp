#include <iostream>

using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    
    string answer= (a < b && b < c) ? "Yes" : "No";

    cout << answer << endl;
    
    return 0;
}