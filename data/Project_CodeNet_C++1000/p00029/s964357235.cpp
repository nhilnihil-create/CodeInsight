#include<iostream>
#include<algorithm>
using namespace std;
main(){
	string str[33],tmp;
	int data[33];
	for(int i=0;i<=33;++i)data[i]=0;
	int k=0;
	while(cin>>tmp){
		//if(tmp=="nil")break;
		for(int i=0;i<=k;++i){
			if(str[i]==tmp){
				data[i]++;
				break;
			}
			if(i==k){
				str[i]=tmp;
				data[i]++;
				++k;
				break;
			}
		}
	}
	string a;
	int ans[2]={0,0};
	for(int i=0;i<=k;++i){
		if(data[i]>data[ans[0]]){
			ans[1]=data[i];
			ans[0]=i;
		}
	}
	a=str[ans[0]];
	ans[0]=ans[1]=0;
	for(int i=0;i<=k;++i){
		if(ans[1]<str[i].size()){
			ans[1]=str[i].size();
			ans[0]=i;
		}
	}
	cout<<a<<" "<<str[ans[0]]<<endl;
	
}