#include <iostream>
using namespace std;

int main() {
	int h,w,x;
    while(1){
        cin >> h >> w;
        if(h==0 && w==0)
            break;
        while(h > 0){
            x = w;
            while(x > 0){
                cout <<"#";
                x--;
            } 
            cout <<endl;
            h--;
        }
        cout <<endl;
    }
    return 0;
}