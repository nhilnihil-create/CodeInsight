#include <iostream>
#include <stdio.h>

using namespace std;

/*int main (){
	int h, m;
	cin >> h >> m;
	while( h!=0 && m!=0 ){
		for(int i=0; i<h; i++){
			for(int j=0; j<m; j++)
				cout << "#";

	        cout << endl;
		}
	}
	
	return 0;
}
*/




int main (){


	int h, w;
	cin >> h >> w;

	while( h!=0 && w!=0 ){
		for(int i=1; i<=h; i++){
			for(int j=1; j<=w; j++) cout << "#";
			cout << endl;
		}
		cout << endl;
		cin >> h >> w;
	}


	return 0;
}