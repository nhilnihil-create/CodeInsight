#include <iostream>
using namespace std;

int main(){
	int h,w,i,j;
	
	refrain:
	cin>>h;
	cin>>w;
	if(h==0&&w==0) return 0;
	
	for(i=0;i<h;i++){
		if(i%2==0){
			for(j=0;j<w;j++){
				if(j%2==0) cout<<"#";
				else cout<<".";
			}
		}
		else{
			for(j=0;j<w;j++){
				if(j%2==0) cout<<".";
				else cout<<"#";
			}
		}
		cout<<endl;
	}
	cout<<endl;
	
	goto refrain;
}