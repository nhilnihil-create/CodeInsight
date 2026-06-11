#include<iostream>
#include<string>
using namespace std;
int main(){
	for(;;){
	int H,W;
	cin>>H>>W;
	if(H==0&&W==0)break;
	if(H%2==0&&W%2==0){
		for(int i=0;i<H/2;i++){
			for(int j=0;j<W/2;j++){
				cout<<"#.";
			}cout<<endl;
			for(int k=0;k<W/2;k++){
				cout<<".#";
			}cout<<endl;
		}
	}
	if(H%2==0&&W%2==1){
		for(int l=0;l<H/2;l++){
			for(int m=0;m<(W-1)/2;m++){
				cout<<"#.";
			}
			cout<<"#"<<endl;
			for(int n=0;n<(W-1)/2;n++){
				cout<<".#";
			}
			cout<<"."<<endl;
		}
	}
	if(H%2==1&&W%2==0){
		for(int o=0;o<(H-1)/2;o++){
			for(int p=0;p<W/2;p++){
				cout<<"#.";
			}cout<<endl;
			for(int q=0;q<W/2;q++){
				cout<<".#";
			}cout<<endl;
		}
		for(int r=0;r<W/2;r++){
			cout<<"#.";
		}cout<<endl;
	}
	if(H%2==1&&W%2==1){
		for(int s=0;s<(H-1)/2;s++){
			for(int t=0;t<(W-1)/2;t++){
				cout<<"#.";
			}
			cout<<"#"<<endl;
			for(int u=0;u<(W-1)/2;u++){
				cout<<".#";
			}
			cout<<"."<<endl;
		}
		for(int v=0;v<(W-1)/2;v++){
			cout<<"#.";
		}
		cout<<"#"<<endl;
	}cout<<endl;
	}
}

