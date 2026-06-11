#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int i,x;
    
    for ( i = 1; i < 100000; i++ ){
        
        cin >> x;
        
        if ( x == 0 ) break;
        
        cout << "Case " << i << ": " << x << endl;
        
    } 
    return 0;
}
