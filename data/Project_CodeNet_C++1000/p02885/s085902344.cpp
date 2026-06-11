#include <iostream>
#include <vector>
using namespace std;
int main(void){
    // Your code here!
    int a,b;
    cin >> a >> b;
    
    if( a > b * 2){
        cout << a - b * 2 << endl;
    }
    else{
        cout << '0' << endl;
    }
    
}