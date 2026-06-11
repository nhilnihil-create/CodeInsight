#include <bits/stdc++.h>
using namespace std;

int main () {
    string N;
    cin >> N;
    char a=N.at(0);
    char b=N.at(1);
    char c=N.at(2);
    
    if (a=='7' || b=='7' || c=='7') {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
