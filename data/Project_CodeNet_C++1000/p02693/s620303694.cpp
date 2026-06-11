#include <iostream>
#include <math.h>
#include <ctype.h>
#include <string.h>

using namespace std;

int main() {

    int k,a,b;
    cin>>k>>a>>b;

    int rem = a % k;

    if(rem == 0) {
        cout<< "OK";
    }
    else {

    rem = k - rem;

    if(rem + a <= b) {
        cout<< "OK";
    }
        else {
        cout<<"NG";
    }
    
    }

}

