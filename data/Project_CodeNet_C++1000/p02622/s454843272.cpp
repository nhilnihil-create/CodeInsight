#include <iostream>
#include <cstring>
using namespace std;
long r,i;
string s,t;
int main() {
    cin >> s >> t;
    r = 0;
    for(i = 0; i < s.length(); i++) {
        if(s[i] != t[i]) r++;
    }
    cout << r;
    return 0;
}