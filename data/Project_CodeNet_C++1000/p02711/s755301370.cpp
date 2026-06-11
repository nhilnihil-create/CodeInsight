#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;

    if (find(s.begin(), s.end(), '7') != s.end()){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}