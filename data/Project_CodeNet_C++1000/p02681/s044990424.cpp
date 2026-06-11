#include <iostream>
#include <string>
using namespace std;
int main(){
    string S,T;
    cin >> S >> T;
    int sl, tl;
    sl = (int) S.length();
    tl = (int) T.length();
    if (sl + 1 != tl) {
        cout << "No" << endl;
        return 0;
    }
    for (int i=0; i<sl; i++){
        if (S.at(i) != T.at(i)){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}