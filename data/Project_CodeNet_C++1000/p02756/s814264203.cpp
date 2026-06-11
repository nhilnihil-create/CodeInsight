#include<iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    string start, end;
    int p = 0;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            p = 1 - p;
        }
        else {
            int f;
            cin >> f;
            char c;
            cin >> c;
            if(f == 1 && p == 0 || f == 2 && p == 1) {
                start.push_back(c);
            }
            else {
                end.push_back(c);
            }
        }
    }
    if(p == 0) {
        for(int i = 0; i < start.length(); i++) {
            cout << start[start.length() - i - 1];
        }
        for(int i = 0; i < s.length(); i++) {
            cout << s[i];
        }
        for(int i = 0; i < end.length(); i++) {
            cout << end[i];
        }
    }
    else {
        for(int i = 0; i < end.length(); i++) {
            cout << end[end.length() - i - 1];
        }
        for(int i = 0; i < s.length(); i++) {
            cout << s[s.length() - i - 1];
        }
        for(int i = 0; i < start.length(); i++) {
            cout << start[i];
        }        
    }
    cout << "\n";
}