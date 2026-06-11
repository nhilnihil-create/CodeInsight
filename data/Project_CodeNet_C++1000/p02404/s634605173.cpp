#include <iostream>
using namespace std;

int main()
{
    int h,w,i,j;
    while(true){
        cin >> h >> w;
        if(h == 0 && w == 0) break;
        char o = '#';
        for(i = 0; i <h; i++){
            for(j = 0; j < w; j++){
                cout << o;
                if(j == 0 ) o = '.';
                if(j == w-2 || i == 0 || i == h-1) o = '#';
            }
            cout << '\n';
        }
        cout << endl;
    }
}