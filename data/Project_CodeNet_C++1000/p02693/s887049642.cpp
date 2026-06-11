#include <iostream>
using namespace std;
 
int main() {
 
	int x, a, b;
    
    cin >> x;
    cin >> a >> b;
    
   	int i;
    for(i = a; i <= b; ++i)
    	if(i % x == 0)
        	break;
	
    if(i == b + 1)
    	cout << "NG" << endl;
    else
    	cout << "OK" << endl;
        
    return 0;
}