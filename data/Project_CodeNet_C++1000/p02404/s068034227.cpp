#include <iostream>
using namespace std;

int main(){
	int h,w,i;
	
	refrain:
	cin>>h;
	cin>>w;
	
	if(h==0&&w==0) return 0;
	
	for(i=0;i<w;i++){
		cout<<"#";
	}
	cout<<endl;
	for(i=2;i<h;i++){
		cout<<"#";
		for(int j=2;j<w;j++){
			cout<<".";
		}
		cout<<"#"<<endl;
	}
	for(i=0;i<w;i++){
		cout<<"#";
	}
	cout<<endl;
	cout<<endl;
	
	goto refrain;
}