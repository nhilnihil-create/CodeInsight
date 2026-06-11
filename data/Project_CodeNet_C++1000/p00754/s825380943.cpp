#include<iostream>
#include<string>
using namespace std;

int main()
{

	string text;

	getline(cin,text);
	while(text[0] != '.'){
		int ans=1 ,brac[100]={0} ,n=0;
		for(int i=0 ; text[i]!='.'; i++){
			//test	cout<<(int)text[i]<<" ";
			if(text[i]=='('){
				brac[n]=1;
				n++;
			}
			if(text[i]==')'){
				if(n==0) ans=0;
				else if(brac[n-1]!=1) ans=0;
				else{
					n--;
					brac[n]=0;
				}
			}
			if(text[i]=='['){
				brac[n]=2;
				n++;
			}
			if(text[i]==']'){
				if(n==0) ans=0;
				else if(brac[n-1]!=2) ans=0;
				else{
					n--;
					brac[n]=0;
				}
			}
			if(ans==0) break;
		}
		if(ans==0 ||  n!=0) cout<<"no"<<endl;
		else cout<<"yes"<<endl;
		getline(cin,text);
	}
}