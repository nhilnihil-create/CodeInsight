#include <iostream>
using namespace std;

int k;

int main() {
    cin >> k;
    if(k%2 == 0 || k%5 == 0) {
        cout << -1;
        return 0;
    }

    int n = 0, i = 1;
    while(true) {
        n = (n*10+7)%k;
        if(n == 0) {
            cout << i;
            return 0;
        }
        i++;
    }
}
