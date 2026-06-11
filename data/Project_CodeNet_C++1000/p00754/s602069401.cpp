#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main(){

	bool F=true;bool R=true;
while(1){char str[250]={},ch;
	for(int i=0;i<245;i++)
	{scanf("%c",&ch);if(ch=='.'&&R==false&&i==1){F=false;break;}
	if(ch=='.'){break;}
	str[i]=ch;}
	if(F==false){break;}
	int ks=0,kl=0,ms=0,ml=0;
	bool f=true;int p[200]={};int y=0;bool G=true;
	if(str[1]=='.'&&str[0]=='\n')F=false;
	for(int i=0;i<200;i++)
	{

		//cout<<i<<"#"<<y<<"#"<<p[y]<<endl;
		if(str[i]=='('){ms++;y++;p[y]=1;}
	else if(str[i]=='['){ks++;y++;p[y]=5;}
	else if(str[i]==')'){ml++;if(p[y]==5||p[y]==0){f=false;}if(ms<ml){f=false;}y--;}//cout<<i<<" ";}
	else if(str[i]==']'){kl++;if(p[y]==1||p[y]==0){f=false;}if(ks<kl){f=false;}y--;}
	}
	if(F==true){
	if(f!=false&&ms==ml&&ks==kl)cout<<"yes"<<endl;
	else{cout<<"no"<<endl;//<<ms<<ml<<ks<<kl<<endl;
	}
	}
R=false;
}


return 0;
}