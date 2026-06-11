#include <iostream>

using namespace std;

int main(){
	char* s = (char*)calloc(101, sizeof(char));
	cin >> s;
	bool ans_flg = true;
	for(int i = 0; s[i] != '\0'; i++){
		if((i+1) % 2 == 0){
			if(s[i] != 'L' && s[i] != 'U' && s[i] != 'D') ans_flg = false;
		}
		else {
			if(s[i] != 'R' && s[i] != 'U' && s[i] != 'D') ans_flg = false;
		}
	}
	cout << ((ans_flg)?"Yes":"No") << endl;
	
}