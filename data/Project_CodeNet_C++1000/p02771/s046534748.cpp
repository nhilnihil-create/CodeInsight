#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a, b, c;
    cin >> a >> b >> c;
    
    if(a > b)swap (a,b);
    if(b > c)swap (c,b);
    if(a > b)swap (a,b);
    
    
    if(a == b && b != c || b == c && b != a) cout << "Yes" << endl; 
    
    else cout << "No" << endl; 
    
    return 0;
}
