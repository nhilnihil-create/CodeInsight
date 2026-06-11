#include <iostream>
using namespace std;
int main(void){
    int ans;
    int x;
    ans = 0;
    
    for (int i=0;i < 5;i++) {
        
        cin >> x;
        
        if (x == 0 && i == 0) 
            ans += 1;
        
        
        if (x == 0 && i == 1) 
            ans += 2;
        
    
        if (x == 0 && i == 2) 
            ans += 3;
        
    
        if (x == 0 && i == 3) 
            ans += 4;
        

        if (x == 0 && i == 4) 
            ans += 5;
        
    }
    cout << ans << endl;
}