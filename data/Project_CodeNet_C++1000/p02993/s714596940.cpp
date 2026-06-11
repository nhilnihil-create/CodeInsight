#include<iostream>
#include<string>

using namespace std;

int main() {
    string s;
    cin >> s;

    bool f = false;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if(s[i] == s[i+1]) {
            f = true;
        }
    }

    if(f) {
        cout << "Bad"
             << "\n";
    }
    else
    {
        cout << "Good" << "\n";
    }
}