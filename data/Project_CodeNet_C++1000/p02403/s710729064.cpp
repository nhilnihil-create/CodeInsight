#include <iostream>
using namespace std;
int main() {
    int a , b;
    cin>> a >> b;
    while (a > 0 || b > 0 ) {
	    
	    for (int i=1; i<=a; i++) {
		    for (int j=1; j<=b; j++) {
				cout <<'#';  
			}
			cout<< endl;	        
		}
		cout<< endl;
		cin>> a >> b;
	}
	
	
}
    
