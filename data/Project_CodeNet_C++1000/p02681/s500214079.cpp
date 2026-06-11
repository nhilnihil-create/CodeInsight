#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	char* s = (char*)calloc(11,sizeof(char));
	cin >> s;
	
	char* t = (char*)calloc(12,sizeof(char));
	cin >> t;
	
	bool ans = true;
	while(*s != 0){
		if(*t != *s) ans = false;
		t++;
		s++;
	}
	if(ans) cout << "Yes";
	else cout << "No";
	cout << endl;
}
