#include <iostream>
#include <math.h>
#include <stdio.h>
#define PI 3.1415926535897932384626433832795028841971
using namespace std;

int main(){
    int w,h;
    
    while(true){
        cin >> h >> w;
        if(w == 0 && h == 0){
            break;
        }
        
        for(int hh = 0;hh<h;hh++){
            for(int ww = 0;ww<w;ww++){
                cout << '#';
            }
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}