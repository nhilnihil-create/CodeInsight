#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a,b;
    cin >> a >> b;
    
    if(a <= 10){
        int ans = b+100*(10-a);
        cout << ans << endl;
    }
    else{
        cout << b <<endl;
    }
} 

