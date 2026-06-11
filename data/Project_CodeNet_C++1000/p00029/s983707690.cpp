#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    map<string,int> freq;
    int amx = 0, bmx = 0;
    string s, a, b;
    while (cin >> s) {
        freq[s] ++;
        if (amx < freq[s]) {
            amx = freq[s];
            a = s;
        }
        if (bmx < s.size()) {
            bmx = s.size();
            b = s;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}