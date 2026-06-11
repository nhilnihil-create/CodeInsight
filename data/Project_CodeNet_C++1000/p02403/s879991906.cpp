#include <iostream>
using namespace std;
int main() {
    int H,W,i;
    string o;
    while(cin>>H>>W && (H!=0 || W!=0)){
        o = string(W,'#');
        for (i=0;i<H;i++) {
            cout << o << endl;
        }
        cout << endl;
    }
    return 0;
}