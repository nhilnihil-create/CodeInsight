#include "bits/stdc++.h"

using namespace std;

int main (){
	int a,b;
while(cin >> a >> b){
	if(a == 0 && b == 0) break; 
		for(int y = 1;y <= b;y++){
			cout << "#";
		}
		for(int h = 1;h <= (a-2);h++){
		cout << endl << "#";
		for(int x = 1;x <= (b - 2);x++)cout << ".";
		cout << "#";
		}
		cout << endl;
		for(int y = 1;y <= b;y++){
		cout << "#";
		}

	cout << endl << endl;

}
return 0;
}