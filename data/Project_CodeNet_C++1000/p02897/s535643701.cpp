#include <iostream>
using namespace std;
int main(void){
    
    int n,t;
    float a;
    
    cin >> n;
    
    t = 0;
    for(int i = 1;i <= n;i++){
        
        if(i % 2 != 0) t = t  + 1;
    
        
    }
    
    a = ((float)t) / ((float)n);
    
    cout << a << endl;
    
    return 0;
}