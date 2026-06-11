#include<iostream>
using namespace std;
int main() {
    string s,t;
    cin >> s >> t;
    bool Can = true;
    for(int i = 0; i < s.length(); ++i)
        if(s[i] != t[i]) {
            Can = false;
            break;
        }
    if(!Can) cout << "No\n";
    else {
        cout << "Yes\n";
    }
return 0;
}