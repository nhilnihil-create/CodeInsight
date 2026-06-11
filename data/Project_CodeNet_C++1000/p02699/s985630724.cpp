#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int s;
    int w;
    cin >> s;
    cin >> w;
    if (s<w||s==w){
        cout << "unsafe";
    }
    else {
        cout << "safe";
    }
}
