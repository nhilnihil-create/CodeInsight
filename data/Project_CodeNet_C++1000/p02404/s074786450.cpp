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
				if(i==0 || j==0 || i==w-1 ||j==h-1){
				cout<<"#";
				}else{
					cout<<".";
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}

	// your code goes here
	return 0;
}