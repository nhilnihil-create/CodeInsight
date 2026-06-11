#include <iostream>
#include <string>
using namespace std;

string s;
int k = 0;

int main() {
    cin >> s;
    
    for(int i = 0; i < s.size(); i++)
        k = (k + (s[i] - '0')) % 9;
    
    if(k == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

