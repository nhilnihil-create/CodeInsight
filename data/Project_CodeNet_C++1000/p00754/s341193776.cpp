#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;

    while(getline(cin, s), s != ".") {

        bool find = true;
        string world = "";

        for(int i = 0; i < s.size(); ++i) {
            switch(s[i]) {
                case '(':
                case ')':
                case '[':
                case ']':
                    world += s[i];
            }
        }

        while(find) {

            find = false;

            int balance;

            if((balance = world.find("()")) != string::npos) {
                world.erase(balance, 2);
                find = true;
            }
            if((balance = world.find("[]")) != string::npos) {
                world.erase(balance, 2);
                find = true;
            }

        }

        cout << (world.size() ? "no" : "yes") << endl;

    }

}