#include<iostream>
using namespace std;
int main(){
	int a;
	bool stu[31]={false};
	for(int i=0;i<28;i++){
		cin>>a;
		stu[a-1]=true;
	}
	for(int i=0;i<30;i++){
		if(stu[i]==false){
			cout<<i+1<<endl;
		}
	}
	return 0;
}