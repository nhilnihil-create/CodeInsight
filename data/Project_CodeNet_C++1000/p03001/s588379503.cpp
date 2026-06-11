#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
using namespace std;

int main(){
    double w,h;
    int x,y;
    cin >> w >> h >> x >> y;

    int c;

    if(x == w/2 && y == h/2){
        c = 1;
    } else {
        c = 0;
    }

    cout << w*h/2 << " " << c << endl;
}