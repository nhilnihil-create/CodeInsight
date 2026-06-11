#pragma warning(disable:4786)  // VisualC++6.0の警告対策
#include<string>
#include<map>
#include<iostream>
#include<cstdio>

using namespace std;

int main(void){
	map<int,string>ward;

	string in,out,siz,space;
	string::size_type poi=0;
	int x,j,i=0;
	int cnt=0,data=0;
	
	space=' ';
	//mapを使って入力
	while((cin>>in)!=0){
		ward.insert(map<int,string>::value_type(i,in));
		i++;
	}
	poi=ward[i].size();
	siz=ward[i];
	for(j=0;j<i-1;j++){
		if(poi<ward[j].size()){
			poi=ward[j].size();
			siz=ward[j];
		}
		for(x=1;x<i;x++){
			if(ward[j]==ward[x])	cnt++;
		}
		if(data<cnt){
			out=ward[j];
			data=cnt;
		}
		cnt=0;
	}
	
	cout<<out<<space<<siz<<endl;

	return 0;
}