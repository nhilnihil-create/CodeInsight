#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;   cin >> s;
    bool p = (s[0] == '7');
    bool q = (s[1] == '7');
    bool r = (s[2] == '7');

    if (p || q || r)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
    
    return 0;
}