#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int i, q;
    string str;
    cin >> str;
    cin >> q;
    int arg1[q] = {}, arg2[q] = {};
    string state[q] = {}, arg3[q] = {};

    for(i=0; i<q; ++i) {
        cin >> state[i];
        if(!(state[i].compare("print"))) {
            cin >> arg1[i] >> arg2[i];
        }
        else if(!(state[i].compare("reverse"))) {
            cin >> arg1[i] >> arg2[i];
        }
        else if(!(state[i].compare("replace"))) {
            cin >> arg1[i] >> arg2[i] >> arg3[i];
        }
    }

    for(i=0; i<q; ++i) {
        if(!(state[i].compare("print"))) {
            cout << str.substr(arg1[i], arg2[i]+1-arg1[i]) << endl;
        }
        else if(!(state[i].compare("reverse"))) {
            reverse(str.begin()+arg1[i], str.begin()+arg2[i]+1);
        }
        else if(!(state[i].compare("replace"))) {
            str.replace(arg1[i], arg2[i]+1-arg1[i], arg3[i]);
        }
    }

    return 0;
}