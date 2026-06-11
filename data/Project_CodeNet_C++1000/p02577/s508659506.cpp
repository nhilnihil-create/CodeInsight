#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;   cin >> s;
    int tmp = 0;
    for (int i = 0; i < s.length(); i++) 
        tmp = (tmp + (s[i]-'0'))%9;
    if (tmp==0)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
    return 0;
}   