#include <iostream>
using namespace std;
int main() {
    string s, result = "";
    cin >> s;
    for(int i=0; i<s.length(); i++) {
        result += "x";
    }
    cout << result << endl;
}