#include <iostream>
using namespace std;
int main(){
    char c;
    cin >> c;
    if (c == 'z'){
        c = 'a';
    }
    else c = (int)c + 1;
    cout << (char)c << endl;
}