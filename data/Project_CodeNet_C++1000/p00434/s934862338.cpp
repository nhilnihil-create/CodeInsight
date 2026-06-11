#include <iostream>

using namespace std;

bool list[31]={false};

int main(void){
	for(int i=0;i<28;i++){
		int a;
		cin >> a;
		list[a]=true;
	}
	for(int i=1;i<=30;i++)
		if(!list[i])
			cout << i << endl;
	return 0;
}