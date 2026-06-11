#include <iostream>
using namespace std;
int main(){
    string s, t; cin >> s >> t;
    bool a = 1;
    for(int i = 0; i < s.size(); ++i) {
        if(s.at(i) != t.at(i)) a = 0;
    }
    if(a) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}