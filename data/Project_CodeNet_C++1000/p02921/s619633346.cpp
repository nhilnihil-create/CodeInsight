#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    string t;
    int correct = 0;
    cin >> s;
    cin >> t;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == t[i]) {
            correct++;
        }
    }
    cout << correct << endl;
}