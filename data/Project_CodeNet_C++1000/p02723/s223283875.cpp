#include<iostream>
#include<string.h>

using namespace std;

int main(){
	char kata[10];
	cin >> kata;
	if(kata[2] == kata[3] && kata[4] == kata[5]){
			cout << "Yes" << endl;
	}else{
		cout <<"No"<<endl;
	}
	return 0;
}
