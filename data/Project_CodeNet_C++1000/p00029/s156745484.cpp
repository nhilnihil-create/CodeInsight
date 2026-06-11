#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct R{string word;
int nl;int ty;

};

int main(){

	struct R RR[1001]={};
	int i=0;
	string str;
	while(cin>>str){
		RR[i].word=str;RR[i].nl=str.size();RR[i].ty=0;
	i++;
	}
	
	for(int I=0;I<i;I++)
		for(int J=0;J<i;J++)
			if(RR[I].word==RR[J].word)RR[I].ty++;

	string x,y;
	int max1=0,max2=0;

	for(int I=0;I<i;I++)
	{//cout<<RR[I].ty<<endl;
		if(RR[I].nl>max1){x=RR[I].word;max1=RR[I].nl;}
		if(RR[I].ty>max2){y=RR[I].word;max2=RR[I].nl;}}

	cout<<y<<" "<<x<<endl;
return 0;

}