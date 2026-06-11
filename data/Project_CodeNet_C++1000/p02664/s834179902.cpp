#include <iostream>
#include <string>
using namespace std;

string T;

int main() {
    cin >> T;
    for (int i = 0; i != (int)T.size(); ++i)
        if (T[i] == '?')
            T[i] = 'D';
    cout << T;
    return 0;
}