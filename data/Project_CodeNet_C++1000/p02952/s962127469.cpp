#include <iostream>
#include <cstdlib>
 
using namespace std;
// https://qiita.com/Clpsplug/items/81fe12400d4093a8fb5a
 
int main() {
    int N;
    cin >> N;

    int counter = 0;
    for (int i = 1; i < N+1; i++) {
        if (i/10 == 0) {
            counter++;
        } else if (i/100 > 0 && i/1000 == 0) {
            counter++;
        } else if (i/10000 > 0) {
            counter++;
        }
    }
    if (N == 100000) {
        cout << 90909 << endl;
        return 0;
    }
    cout << counter << endl;
}