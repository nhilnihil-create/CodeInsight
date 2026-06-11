#include<iostream>
using namespace std;

int main() {
	int n,x; //nまでの数3つで和がx
	int num = 0;
	
	while (1) {
            num = 0; //激注意
	    cin >> n >> x;
	    if ( n == 0 && x == 0 ) break;
	    for ( int i = 1; i <= n - 2; i++ ) 
	        for ( int j = i + 1; j <= n - 1; j++ ) 
	            for ( int k = j + 1; k <= n; k++ ) {
	        	    if ( i + j + k == x ) num++;
	            }
	    cout << num << endl;
	}
}
