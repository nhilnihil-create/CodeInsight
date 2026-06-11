#include <iostream>
using namespace std;

int main(){
    int h, w;
    while(cin >> h >> w && (h && w)){
        while(h--) cout << string(w, '#') << endl;
        cout << endl;
    }
}