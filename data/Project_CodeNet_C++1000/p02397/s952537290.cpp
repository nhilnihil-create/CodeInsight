#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int i,x,y;
    
    for ( i = 1; i < 3000; i++){
        
        cin >> x >> y;
        
        if ( x ==  0 && y == 0 ) break;
        
        if ( x < y ){ 
        
            
            cout << x << " " << y << endl;
            
        }
        
        if ( x > y ){
            
            
            cout << y << " " << x << endl;
            
        }
        
        if ( x == y){
            
            
            cout << x << " " << y << endl;
            
        }
        
    }
    
    return 0;
}
