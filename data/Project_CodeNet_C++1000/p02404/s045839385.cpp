#include <iostream>

using namespace std;

void printRectangle(int height, int width) {
    for (int row = 0; row < height; ++row) {
        string line;
        bool isTopBottom = (row == 0 || row == height - 1) ? true : false;
        for (int column = 0; column < width; ++column) {
            bool isLeftRightEnd = (column == 0 || column == width - 1) ? true : false;
            line += (isTopBottom || isLeftRightEnd) ? "#" : ".";
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