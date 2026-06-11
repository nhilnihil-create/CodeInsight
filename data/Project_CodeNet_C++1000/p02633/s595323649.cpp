#include<iostream>

using namespace std;

int gcd(int a, int b){
    //cout << a << "," << b << endl;
    if( b == 0 ){
        return a;
    }
    if( a < b ){
        a ^= b;
        b ^= a;
        a ^= b;
    }
    return gcd(b, a % b);
}

int main(){
    int X;

    cin >> X;
    cout << ( (X * 360) / gcd(360,X) ) / X << endl;
   
}