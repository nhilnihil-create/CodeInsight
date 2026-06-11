#include<iostream>
#include<string.h>

using namespace std;

int main(){
	char kata1[10];
	char kata2[10] = "ABC";
	cin >> kata1;
	if(strcmp(kata1,kata2) == 0){
		cout << "ARC "<< endl;
	}else{
		cout << "ABC"<< endl;
	}
	
	return 0;
}
