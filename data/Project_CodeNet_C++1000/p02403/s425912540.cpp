#include <iostream>
using namespace std;

int main()
{
    int h, w;
    
    while(cin >> h >> w && h && w) {
        while(h--) {
            int w0 = w;
            while(w0--) cout << '#';
            cout << '\n';
        }
        cout << endl;
    }
    
    return 0;
}
