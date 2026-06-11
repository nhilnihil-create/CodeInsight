#include <iostream>
using namespace std;
int main(void){
    
    string t;
    cin >> t;
    t = t + t;
    
    string x;
    cin >> x;
    
    if( t.find(x,0) != string::npos){
        cout << "Yes" << endl;
    }
    else{
       cout << "No" << endl;
    }    
}