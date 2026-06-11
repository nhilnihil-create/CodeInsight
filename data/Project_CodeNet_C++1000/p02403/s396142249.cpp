#include    <iostream>
#include    <string>

using namespace std;

int main() {
    while(1) {
        int H, W;

        cin >> H >> W;
        if(H == 0 && W == 0) break;
        
        const string base(W,'#');
        for(int i = 0; i < H; i++)
            cout << base << endl;
        cout << endl;
    }
    return 0;
}
