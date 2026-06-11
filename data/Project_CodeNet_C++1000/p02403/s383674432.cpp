#include <iostream>

using namespace std;

void printRectangle(int height, int width) {
    for (int row = 0; row < height; ++row) {
        string line;
        for (int column = 0; column < width; ++column) {
            line += "#";
        }

        cout << line << endl;
    }

    cout << endl;
}

int main() {
    while (true) {
        int height, width;
        cin >> height >> width;

        if (height == 0 && width == 0) break;

        printRectangle(height, width);
    }

    return 0;
}