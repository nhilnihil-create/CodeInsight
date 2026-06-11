#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h,w;
    char chars[2] = { '#', '.' };
    while(cin >> h >> w){
        if(h == 0 && w == 0)
            return 0;

        int row_switch = 0;
        int char_switch = 0;
        for (int row = 0; row < h; row++ ){
            if(row_switch == 0)
                char_switch = 0;
            else
                char_switch = 1;

            for(int col = 0; col < w; col++ ){
                cout << chars[char_switch];
                char_switch = (char_switch + 1) % 2;
            }
            cout << endl;
            row_switch = (row_switch + 1) % 2;
        }

        cout << endl;
    }

    return 0;
}