#include <iostream>
#include <math.h>
using namespace std;
int main(void){
    double n,d;
    cin >> n >> d;
    cout << (int)ceil(n/(d*2+1)) << endl;
}