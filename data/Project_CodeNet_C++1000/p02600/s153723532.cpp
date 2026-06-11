#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int x; cin >> x;
    int num = 600, cnt = 0;
    while(x >= num) {
        num += 200;
        cnt++;
    }
    cout << 8 - cnt << endl;
}