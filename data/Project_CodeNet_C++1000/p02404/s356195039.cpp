#include <iostream>
using namespace std;

int main() {
	int h,w,x,y;
    while(1){
        cin >> h >> w;
        y = h;
        if(h==0 && w==0)
            break;
        while(h > 0){
            x = w;
            while(x > 0){
                if(x==1 || x==w || h==1 || h==y)
                    cout <<"#";
                else
                    cout <<".";
                x--;
            } 
            cout <<endl;
            h--;
        }
        cout <<endl;
    }
    return 0;
}