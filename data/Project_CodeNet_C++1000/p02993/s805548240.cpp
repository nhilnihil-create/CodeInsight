#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    string s; cin >> s;
    char prev = s[0];
    for(int i = 1; i < s.size(); ++i) {
        if(prev == s[i]) {cout << "Bad"; return 0;}
        prev = s[i];
    }
    cout << "Good";
}