#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int count = 1;
    vector<int> x(5);
    for (int i = 0; i < 5; i++) {
        cin >> x.at(i);
    }
    
    for (int i = 0; i < 5; i++) {
        if (x.at(i) == 0) {
            count += i;
        }
    }

    cout << count << endl;

}