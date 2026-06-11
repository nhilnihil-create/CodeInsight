#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
    string t;
    cin >> t;
    for(int i = 0; i < t.size(); i++) {
        if(t[i] == '?') {
            t[i] = 'D';
        }
    }

    for(int i = 0; i < t.size(); i++) {
        cout << t[i] << "";
    }
    cout << endl;
    return 0;
}