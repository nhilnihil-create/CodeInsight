#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(void){
	int jage1=0,jage2=0,time;
	char card1[100],card2[100];
	cin>>time;
	for(int abc=0;abc<time;abc++){
		cin>>card1>>card2;
		if(strcmp(card1,card2)>0){
			jage1+=3;
		}else if(strcmp(card1,card2)<0){
			jage2+=3;
		}else{
			jage1++;
			jage2++;
		}
	}
	cout<<jage1<<" "<<jage2<<endl;
	return 0;
}