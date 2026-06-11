#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	char* s = (char*)calloc(n+1, sizeof(char));
	cin >> s;
	
	if(n % 2 != 0) {cout << "No" << endl; return 0;}
	
	char* t = (char*)calloc((n/2)+1, sizeof(char));
	for(int i = 0; i < (n/2); i++){
		t[i] = s[i];
	}
	for(int i = (n/2); i < n; i++){
		if(s[i] != t[i-(n/2)]){
			cout << "No" << endl;
			return 0;
		}
	}
	
	cout << "Yes" << endl;
	return 0;
	
}