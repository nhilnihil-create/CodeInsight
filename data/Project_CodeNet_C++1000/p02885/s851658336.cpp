#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std ;
int A,B;
int main(){
    cin >> A >> B;
    if(A<=2*B){
        cout << "0\n";
        return 0;
    }else{
        int c = A - 2*B;
        cout << c << "\n";
        return 0;
    }
}