#include <iostream>
using namespace std;

int main()
{
    int h, w;
    while (1) {
        cin >> h >> w;
        if (!h && !w) break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << "#";
            }
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}