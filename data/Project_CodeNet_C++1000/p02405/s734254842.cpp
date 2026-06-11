#include <iostream>

using namespace std;

int main(void){
	
	int h,w;
	
	while(cin>>h>>w,w!=0&&h!=0){
		
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if((i+j)%2==0)
					cout<<"#";
				else
					cout<<".";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	
	
}