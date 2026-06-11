#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;

    while ((cin >> h >> w), h != 0 || w != 0) {
        for (int x = 0; x < w; ++x) {
            cout << "#";
        }

        cout << endl;

        for (int y = 1; y < h - 1; ++y) {
            cout << "#";

            for (int x = 1; x < w - 1; ++x) {
                cout << ".";
            }

            cout << "#" << endl;
        }

        for (int x = 0; x < w; ++x) {
            cout << "#";
        }

        cout << endl << endl;
    }


    return 0;
}