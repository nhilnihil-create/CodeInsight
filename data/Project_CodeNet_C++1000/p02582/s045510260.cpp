#include <iostream>

using namespace std;

int main() {
    string s;
    int ans = 0;
    cin >> s;
    for(int i = 0; i < 3; i++) {
        if(s[i] == 'R') {
            ans = 1;
            break;
        }
    }
    for(int i = 0; i < 2; i++) {
        if(s[i] == 'R' && s[i+1] == 'R') {
            ans = 2;
            break;
        }
    }
    if(s[0] == 'R' && s[1] == 'R' && s[2] == 'R') {
        ans = 3;
    }
    cout << ans << endl;
}