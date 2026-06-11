#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a, b, c;
    
    cin >> a >> b >> c;
    
    if(a == b && a != c){
        
        cout << "Yes" << endl;
        
    }
    
    else if(a != b && a == c){
        
        cout << "Yes" << endl;
        
    }
    
    else if(a == c && b !=c){
        
        cout << "Yes" << endl;
        
    }
    
    else if(a != c && b == c){
        
        cout << "Yes" << endl;
        
    }
    
    
    else{
        
        cout << "No" << endl;
        
    }
        
        
        
    
}