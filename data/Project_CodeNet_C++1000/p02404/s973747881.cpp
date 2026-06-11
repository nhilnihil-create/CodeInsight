#include <iostream>
using namespace std;

int main(){
	int H,W;
	while(1){
		cin>>H>>W;
		if(H==0&&W==0){
			break;
		}
		if(H==0||W==0){
			H=W=0;
		}
		for(int i=0;i<W;i++){
			cout<<"#";
			W-=1;
			if(i==W){
				cout<<endl;
			}
			W+=1;
		}
		H-=2;
		W-=2;
		for(int i=0;i<H;i++){
			   cout<<"#";

			   for(int ii=0;ii<W;ii++){
				   cout<<".";
		       }
			   cout<<"#"<<endl;
		}
		W+=2;
		for(int i=0;i<W;i++){
			cout<<"#";
			W-=1;
			if(i==W){
				cout<<endl<<endl;;
			}
			W+=1;
		}

	}

	return 0;
}