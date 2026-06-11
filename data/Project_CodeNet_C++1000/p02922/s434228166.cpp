#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int y, t;
    cin >> y >> t;
    for(int i = 0; i < 21; i++){
        if((y - 1)*i + 1 >= t){
           
            cout << i <<endl;
            break;
        }
        
    }
       return 0;
        
    
        
    
   
    
    
    
    
    
}

