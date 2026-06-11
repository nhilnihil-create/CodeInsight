#include<iostream>
using namespace std;
int main(){
	int H,W,i,j,ans1,ans2,ans3,ans4;
	for(;;){
		cin>>H>>W;
		if(W==0&&H==0)
			break;
		for(i=1;i<=H;i++){
			ans1=i/2*2;
			for(j=1;j<=W;j++){
				ans2=j/2*2;
				if((i==ans1)!=(j==ans2)){
					cout<<'.';
				}else{
					cout<<'#';
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}