#include <iostream>
using namespace std;
int main(void){
    
    int d,t,s;
    cin >> d >> t >> s;
    int x = d / s;
    int y = d % s;
    
    if( y > 0){
        x = x + 1;
    
    if( x > t){
        cout << "No" << endl;
    }
    
    if( x <= t){
        cout << "Yes" << endl;
    }
    }
    
    else if( y == 0){
        if( x > t){
        cout << "No" << endl;
    }
    
    if( x <= t){
        cout << "Yes" << endl;
    }
    }
}