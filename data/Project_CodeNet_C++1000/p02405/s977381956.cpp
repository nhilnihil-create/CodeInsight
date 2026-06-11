#include <iostream>
#include <sstream>

using namespace std;

int main() {

    int H, W;
    stringstream input;
    string out;

    while(1) {
        int A, B;
        cin >> A >> B;
        if (A == 0 && B == 0)
            break;
        input << A << " " << B << endl;
    }

    while(!input.eof()) {
        input >> H >> W;
        if (H == 0 && W == 0)
            break;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                int number = i + j;
                if (number % 2 == 0) {
                    out += "#";
                    continue;
                }
                out += ".";
            }
            out += "\n";
        }
        cout << out << "\n";
        out = "";
        H = 0;
        W = 0;
    }
    return 0;
}