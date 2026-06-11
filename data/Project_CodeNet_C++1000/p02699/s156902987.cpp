#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int s,w;
    cin >> s >> w;
    if( s <= w){
        cout << "unsafe" << endl;
    }
    else{
        cout << "safe" << endl;
    }
}