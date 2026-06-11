#include <iostream>
#include <string>

int main() {
    using namespace std;
    int n;
    string s;
    cin >> n >> s;
    string out;
    out = "";
    char next;
    // cout << s.size();
    for (int i=0; i < s.size(); i++){
        // cout << s[i] + n;
        next = s[i] + n;
        if (next > 'Z') next = s[i] + n - 26;
        out += next;
        // cout << out;
    }
    cout << out;
}