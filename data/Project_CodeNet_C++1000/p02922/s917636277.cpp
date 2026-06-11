#include <iostream>
using namespace std;

int main() {
    int a,b;
    int ans = 0;
    cin >> a >> b;
    if(b == 1){
        cout << 0;

    }else {
        ans++;
        b -= a;
        while (b >= 1) {
            ans++;
            b -= a - 1;
        }
        cout << ans;
    }
    return 0;
}