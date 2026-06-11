#include <iostream>
using namespace std;

int main() {
    int x; cin >>x;
    bool ret = 0;

    for (int i = 1; i < 1000; i++) {
        if (i*100<=x && x<=105*i) {ret = 1; break;}
    }
    if (x==100000) ret = 1;

    cout << ret << endl;
    return 0;
}