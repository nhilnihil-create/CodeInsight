#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string S; cin >> S;
    vector<string> V = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    for (int i = 0; i < V.size(); ++i) {
        if (S == V[i]) {
            cout << 7 - i << endl;
            break;
        }
    }
}
