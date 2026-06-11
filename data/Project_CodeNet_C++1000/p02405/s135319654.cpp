#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    while (1) {
        int h, w;
        cin >> h >> w;

        if (h == 0 && w == 0) {
            break;
        }

        for (int row = 0; row < h; row++) {
            for (int col = 0; col < w; col++) {
                if ((row + col) % 2 == 0) {
                    cout << "#";
                } else {
                    cout << ".";
                }
            }
            cout << endl;
        }

        cout << endl;
    }

    return 0;
}