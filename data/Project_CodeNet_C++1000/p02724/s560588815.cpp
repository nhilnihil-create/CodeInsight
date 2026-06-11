#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int g = 0;
    while(n >= 500){
        n = n - 500;
        g = g + 1000;
    }
    while(n >= 5){
        n = n - 5;
        g = g + 5;
    }
    cout << g;
    return 0;
}