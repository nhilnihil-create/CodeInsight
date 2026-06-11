#include<iostream>
using namespace std;
int main (void){

    int a, b, c, i;
    int aa, bb;
    int flag = 0;

    cin >> a >> b;


    if(a < b)
    c = b;
    else
    c = a;

    for(i = 0;i < c;i++){
        aa = 0,bb = 0;

        aa = a - i;
        bb = b - i;
        
        if(aa < 0)
            aa *= -1;
        if(bb < 0)
            bb *= -1;

        if(aa == bb){
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    cout << i << endl;
    else
    cout << "IMPOSSIBLE" << endl;

    return 0;
}