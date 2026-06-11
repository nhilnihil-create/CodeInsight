#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long h, ans = 0;
    cin >> h;
    int i = 0;
    while(h >= 1){
        ans += pow(2, i);
        h /= 2;
        i++;
    }
    cout << ans;
    return 0;
}