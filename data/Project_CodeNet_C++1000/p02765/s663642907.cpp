#include <iostream>
using namespace std;
int main(void){
    
    int a, b;
    cin >> a >> b;
    
    if(a < 10) cout << b + ((10 - a)*100) <<endl;
    else cout << b << endl;
    
    
    return 0;
    
}
