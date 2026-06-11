#include <iostream>
using namespace std;

string s;

int main() {
    cin >> s;
    for (char &i:s){
        if (i == '?') i = 'D';
    }
    cout << s;
}
