#include <iostream>
using namespace std;

int main() {
	int h,w;
	for(int j=0;j<1000;j++){
		cin>>h>>w;
		if(h==0 && w==0){
			break;
		}
		for(int j=0;j<h;j++){
			for(int i=0;i<w;i++){
				cout<<"#";
			}
			cout<<endl;
		}
		cout<<endl;
	}

	// your code goes here
	return 0;
}