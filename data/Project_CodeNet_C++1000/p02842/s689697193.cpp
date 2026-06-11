#include <iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    for(int i = 0; i <= n; ++i) {
        int x = (int)(i * 1.08);
        if(x == n) {
            cout << i;
            return 0;
        }
    }
    cout << ":(";
    return 0;
}