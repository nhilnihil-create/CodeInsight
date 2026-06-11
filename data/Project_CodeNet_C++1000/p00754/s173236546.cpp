#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;

int s(string str, int j) {
    int i = j;
    if (str[i] == '(') {
        while(true) {
            i++;
            if (str[i] == ')') {
                return i;
            } else if (str[i] == '[' || str[i] == '(') {
                i = s(str, i);
                if (i == -1) {
                    return -1;
                }
            } else if (str[i] == ']' || str[i] == '.') {
                return -1;
            }
        }
    } else {
        while(true) {
            i++;
            if (str[i] == ']') {
                return i;
            } else if (str[i] == '[' || str[i] == '(') {
                i = s(str, i);
                if (i == -1) {
                    return -1;
                }
            } else if (str[i] == ')' || str[i] == '.') {
                return -1;
            }
        }
    }
}

int main() {
    while(true) {
        int i;
        int cntr = 0;
        int cntk = 0;
        int result = 0;
        string ch;

        getline(cin, ch);
        for (i = 0; i < 100; i++) {
            if (ch[i] == '(' || ch[i] == '[') {
                result = s(ch, i);
                i = result;
                if (result == -1) {
                    break;
                }
            } else if (ch[i] == ')' || ch[i] == ']') {
                result = -1;
                break;
            } else if (ch[i] == '.') {
                result = 0;
                break;
            }
        }
        if (ch[0] == '.') {
            break;
        } else if (result != -1) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}
