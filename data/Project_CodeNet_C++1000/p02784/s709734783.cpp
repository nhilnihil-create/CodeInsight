#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int h, n, ai, s;
    s = 0;
    cin >> h >> n;
    for (int i=0; i<n; i++){
        cin >> ai;
        s += ai;
    }
    // if (s < h) {
    //     cout << "No";
    // } else {
    //     cout << "Yes";
    // }

    puts(s<h?"No":"Yes");
}