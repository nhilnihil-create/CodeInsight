#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int H,A;
    cin >> H >> A;
    int W = H % A;
    if(W == 0){
        cout << H / A << endl;
    }
    else{
        cout << H / A + 1 << endl;
    }
}
