#include <iostream>
#include <sstream>

using namespace std;

int main() {

    int H, W; 
    stringstream input;
    string out;

    // 1????????? stream ?????????.
    while(1) {
        int A, B;
        cin >> A >> B;
        // 0 0 ??§??????.
        if ( A == 0 && B == 0)
            break;
        input << A << " " << B << endl;
    }

    // stream ?????????????????????
    while (!input.eof()) {
        input >> H >> W;
        if (H == 0 && W == 0)
            break;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                out += "#";
            }
            out += "\n";
        }
        cout << out << "\n";
        out = "";
        // ?????????.
        H = 0;
        W = 0;
    }
    return 0;
}