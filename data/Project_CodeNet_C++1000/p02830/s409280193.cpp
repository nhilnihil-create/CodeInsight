#include <iostream>
#include <string>

int main() {
    using namespace std;
    int n;
    string s,t, out;
    cin >> n;
    cin >> s >> t;
    // cout << s;
    out = "";
    for (int i=0; i<n; i++){
        // out += s[i] + t[i];
        cout << s[i] << t[i];
    }
    
}