#include<iostream>

using std::cout;
using std::endl;
using std::cin;

void checkEvenOrOdd(int i, int j) {
    if ((i + j) % 2 == 0) {
            cout << "#";  
    } else {
            cout << ".";  
    }
    
}

void output(int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            checkEvenOrOdd(i, j); 
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