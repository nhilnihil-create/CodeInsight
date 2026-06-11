#include <iostream>
using namespace std;

int main(){
	int num[3];
	int tmp;
	for(int n=0;n<3;n++)cin>>num[n];
	for(int x=0;x<3;x++){
		for(int y=2;y>0;y--){
			if(num[y]<num[y-1]){
				tmp=num[y];
				num[y]=num[y-1];
				num[y-1]=tmp;
			}
		}
	}
	cout<<num[0]<<" "<<num[1]<<" "<<num[2]<<endl;
	return 0;
}
