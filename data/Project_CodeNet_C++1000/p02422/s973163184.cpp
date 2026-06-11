#include<iostream>
#include<string>
using namespace std;

int main(){
	string str,str2,cmd,p;
	int q,a,b;
	cin>>str;
	cin>>q;
	for(int k=0;k<q;k++){
		cin>>cmd;
		if(cmd=="print"){
			cin>>a>>b;
			str2=str.substr(a,b-a+1);
			cout<<str2<<endl;
		}
		else if(cmd=="reverse"){
			cin>>a>>b;
			str2=str.substr(a,b-a+1);
			int j=0;
			for(int i=b;i>=a;i--){
				str[i]=str2[j];
				j++;
			}
		}
		else if(cmd=="replace"){
			cin>>a>>b>>p;
			int m=0;
			for(int i=a;i<=b;i++){
				str[i]=p[m];
				m++;
			}
		}
	}
}
