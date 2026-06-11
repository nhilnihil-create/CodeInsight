#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    string T;
    cin >> T;
    replace(T.begin(), T.end(), '?', 'D');
    cout << T << endl;
    return 0;
}
