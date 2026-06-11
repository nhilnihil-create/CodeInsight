#include<iostream>
using namespace std;
int main() {
    int k;
    string s;
    cin >> k >> s;
    if(s.length() <= k) {
        cout << s << '\n';
    } else {
        for(int i = 1; i <= k; ++i) cout << s[i-1];
        cout << "...\n";
    }
}