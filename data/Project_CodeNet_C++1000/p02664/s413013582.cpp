#include<bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a;
	cin>>a;
	string x;
	string y;
	
	for(int i=0;i<a.length();i++){
		if(a.at(i)=='?'){
			x+='D';
		}else{
			x+=a.at(i);
		}
	}
	int count1=0;
	for(int i=0;i<x.length();i++){
		if(x.at(i)=='D'){
			count1+=1;
		}
	}
	for(int i=0;i<x.length()-1;i++){
		if(x.at(i)=='P' && x.at(i+1)=='D'){
			count1+=1;
		}
	}
	for(int i=0;i<a.length();i++){
		if(a.at(i)=='?'){
			y+='P';
		}else{
			y+=a.at(i);
		}
	}
	int count2=0;
	for(int i=0;i<y.length();i++){
		if(y.at(i)=='D'){
			count2+=1;
		}
	}
	for(int i=0;i<y.length()-1;i++){
		if(y.at(i)=='P' && y.at(i+1)=='D'){
			count2+=1;
		}
	}
	if(count1>count2){
		cout<<x<<"\n";
	}else{
		cout<<y<<"\n";
	}


 
	
	
	
	
	return 0;
}