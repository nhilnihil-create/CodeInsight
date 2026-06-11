#include <iostream>
#include <stdio.h>
using namespace std;
 
int main(){
	int h,w,flag,i,j;
	char a,b;
	a='#';
	b='.';
	
	while (1) {
		cin >> h >> w;
		if (h==0&&w==0) {
			break;
		}
		
		for (i=0;i<h;i++) {
			for (j=0;j<w;j++) {
				flag=i+j;
				if ( flag % 2 == 0 ) {
					cout << a;
				}else{
					cout << b;
				}
			}
			cout << endl;
		}
		cout << endl;
	}
    return 0;
}