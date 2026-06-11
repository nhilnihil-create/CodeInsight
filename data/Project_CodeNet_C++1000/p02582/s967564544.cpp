#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(void) {
    unordered_map<string, int> m;
    m["SSS"] = 0;
    m["SRR"] = 2;
    m["RRS"] = 2;
    m["RSR"] = 1;
    m["RRR"] = 3;
    m["SSR"] = 1;
    m["RSS"] = 1;
    m["SRS"] = 1;

    string s;
    cin >> s;
    cout << m[s] << endl;
    return 0;
}