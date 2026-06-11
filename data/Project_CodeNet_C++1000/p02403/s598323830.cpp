#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;

    while ((cin >> h >> w), h != 0 || w != 0) {
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                cout << "#";
            }

            cout << endl;
        }

        cout << endl;
    }


    return 0;
}