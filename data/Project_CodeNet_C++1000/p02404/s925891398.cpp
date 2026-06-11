#include<iostream>

using std::cout;
using std::endl;
using std::cin;


void output(int h, int w) {
    for (int i = 0; i < h; i++) {
        if (w >= 1) {
            cout << "#";  
        }

        for (int j = 1; j < w - 1; j++) {
            if (i == 0 || i == h - 1) {
                cout << "#";  
            } else {
                cout << ".";  
            }
        }

        if (w > 1) {
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