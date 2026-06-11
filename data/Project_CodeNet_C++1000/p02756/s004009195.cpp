
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

void Main() {
    // input
    string S;
    cin >> S;



    // translate
    bool isReverse = false;
    u_int32_t Q;
    cin >> Q;
    string front;
    string back;
    for (u_int32_t i = 0; i < Q; i++) {
        int T, F;
        char C;
        cin >> T;
        if (T == 1) {
            isReverse = !isReverse;
        } else if (T == 2) {
            cin >> F >> C;
            if (F == 1) {
                if (isReverse) {
                    back.push_back(C);
                } else {
                    front.push_back(C);
                }
            } else if (F == 2) {
                if (isReverse) {
                    front.push_back(C);
                } else {
                    back.push_back(C);
                }
            } else {
                cout << "Error" << endl;
            }

        } else {
            cout << "Error" << endl;
        }
    }



    // output
    if (!isReverse) {
        reverse(front.begin(), front.end());
        cout << front << S << back << endl;;
    } else {
        reverse(back.begin(), back.end());
        reverse(S.begin(), S.end());
        cout << back << S << front << endl;;
    }


}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
