#include    <iostream>
#include    <string>

using namespace std;

int main() {
    while(1) {
        int H, W;

        cin >> H >> W;
        if(H == 0 && W == 0) break;
        
        const string base(W,'#');
        const string side(W-2,'.');

        cout << base << endl;
        for(int i = 1; i < H-1; i++)
            cout << '#' << side << '#' << endl;
        cout << base << endl;
        cout << endl;
    }
    return 0;
}
