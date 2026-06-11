#include <iostream>

using namespace std;

int main() {
    int n; 
    int tmp = 1000;
    cin >> n;

    while (n > tmp)
        tmp += 1000;

    cout << tmp - n << endl;

    return 0;
}