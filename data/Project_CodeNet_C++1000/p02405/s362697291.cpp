#include <iostream>
using namespace std;
 
int main() {
    int h,w,x,k;
    while(1){
        cin >> h >> w;
        k =0;
        if(h==0 && w==0)
            break;
        while(h > 0){
            x = w;
            while(x > 0){
                if(k%2 == 0)
                    cout <<"#";
                else
                    cout <<".";
                x--;
                k++;
            }
            cout <<endl;
            h--;
            if(w%2 ==0)
                k++;
        }
        cout <<endl;
    }
    return 0;
}