#include<iostream>
using namespace std;
int x, y;
int cmmdc(int a, int b){
    int r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main(){
    cin>> x;
    y = 360 * x / cmmdc(x, 360);
    cout<< y / x;
}
