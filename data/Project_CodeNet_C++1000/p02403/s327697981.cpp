#include<iostream>

using std::cout;
using std::endl;
using std::cin;


void output(int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << "#";  
        }
        cout << endl;
    }
    cout << endl;
    return;
}

int main(void) {
    int h;
    int w;

    cin >> h >> w;

    while (h != 0 && w != 0) {
        output(h, w);
        cin >> h >> w;
    }

    return 0;
}