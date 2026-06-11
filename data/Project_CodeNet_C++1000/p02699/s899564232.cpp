#include<iostream>
#include<string.h>

using namespace std;

int main(){
	int S = 0;
	int W = 0;
	cin >> S;
	cin >> W;
	if(S > W){
		cout <<"safe"<< endl;
	}else{
		cout <<"unsafe"<<endl;	
	}
	return 0;
}
