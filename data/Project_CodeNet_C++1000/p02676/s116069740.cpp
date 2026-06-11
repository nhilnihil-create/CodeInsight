#include <iostream>

using namespace std;

int main(){
	int k;
	char* s = (char*)calloc(100, sizeof(char));
	cin >> k >> s;
	for(int i = 0; i < k; i++){
		if(s[i] == 0) break;
		cout << s[i];
	}
	int len = 0;
	while(*s != 0){
		s++;
		len++;
	}
	if(len > k) cout << "..." << endl;
}