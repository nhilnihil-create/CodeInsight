#include<iostream>
using namespace std;
int main(){
		int H[100],W[100];
		int count=0;
while(true){
	int a,b;
	cin>> a>>b;
	if(a==0&&b==0){
		break;
	}
	else{
		H[count]=a;
		W[count]=b;
		count=count++;
	}
}
for (int l=0;l<count;l++){
	for(int i=0;i<H[l];i++){
		for (int j=0;j<W[l];j++){
			cout<<"#";
		}
		cout<<endl;
	}
	cout<<endl;
}
	return 0;
}