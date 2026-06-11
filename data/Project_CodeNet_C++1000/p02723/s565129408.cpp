#include <iostream>

using namespace std;

int main(){
	char* c = (char*)malloc(sizeof(char)*6);
	for(int i = 0; i < 6; i++){
		cin >> c[i];
	}
	if(c[2] == c[3] && c[4] == c[5]) cout << "Yes";
	else cout << "No";
	
	cout << endl;
}