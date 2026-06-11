#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cstdlib>

using namespace std;

class c_gcd
{
private:

   
public:
   int f_gcd(int a,int b);
};

int c_gcd::f_gcd(int x,int y)
{
    //cout << "x = " << x << endl;
    //cout << "y = " << y << endl;
    
    if (y != 0){
        c_gcd::f_gcd(y,x % y);
    }else{
        cout << x << endl;
        return 0;
    }
    
}

int main(){
    int a,b;
   
    c_gcd gcd01;
    
    cin >> a >> b;
    
    gcd01.f_gcd(a,b);
    
    return 0;
}