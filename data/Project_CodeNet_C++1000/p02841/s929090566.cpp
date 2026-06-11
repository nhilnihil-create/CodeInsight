#include<bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n1,m1,n2,m2;
	cin>>n1>>m1;
	cin>>n2>>m2;
	vector<int>v{4,6,9,11};
	vector<int>x{1,3,5,7,8,12,10};
	int count=0;
	for(int i=0;i<v.size();i++){
		if(v.at(i)==n1){
			count=1;
		}
	}
	for(int i=0;i<x.size();i++){
		if(x.at(i)==n1){
			count=2;
		}
	}
	if(count==0 && m1==28){
		cout<<1<<"\n";
		
	}else if(count==1){
		if(m1==30){
			cout<<1<<"\n";
		}else{
			cout<<0<<"\n";
		}
	}else if(count==2){
		if(m1==31){
			cout<<1<<"\n";
		}else{
			cout<<0<<"\n";
		}
	}else{
		cout<<0<<"\n";
	}
	



	


 
	
	
	
	
	return 0;
}