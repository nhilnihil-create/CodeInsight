#include <iostream>

using namespace std;

int main(void) {
        int W, H;
        int x, y, r;
        int w, h;

        cin >> W >> H >> x >> y >> r;
        
        w = W - x;
        h = H - y;
        
        if(r > w || r > h || x < 0 || y < 0) {
                cout << "No" << endl;
        } else {
                cout << "Yes" << endl;
        }

        return 0;
}