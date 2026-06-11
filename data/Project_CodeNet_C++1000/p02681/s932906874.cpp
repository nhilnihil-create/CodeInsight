#include <iostream>
#include <math.h>
#include <ctype.h>
#include <string.h>

using namespace std;

int main() {

    string s,t;
    bool check = true;

    cin>>s>>t;

    if(s.length() + 1 == t.length()) {
        for(int i = 0; i < s.length(); i++ ) {
            if(s.at(i) != t.at(i)) {
                check = false;
                break;
            }
        }
    }

    if(check == false) {
        cout<< "No";
    }
    else {
        cout<< "Yes";
    }

}

