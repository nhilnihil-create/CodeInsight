#include<iostream>
#include<map>
#include<string>
using namespace std;


map<string,int>data;
int main(){
	
	string str;
	int ma;
	string ans1,ans2;
	while(cin>>str){
		data[str]++;
		if(ma<data[str]){
			ma=data[str];
			ans1=str;
		}
		if(ans2.size()<str.size())ans2=str;
	}
	cout<<ans1<<" "<<ans2<<endl;
}