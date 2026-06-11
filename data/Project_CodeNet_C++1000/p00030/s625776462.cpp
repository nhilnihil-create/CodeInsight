#include<iostream>
using namespace std;
int ans;
bool def_2(int i,int j,int s){
	if(j==0){
		if(s==0){
			ans++;
		}else return false;
	}
	if(i>9)return false;
	if(s<=0)return false;
	def_2(i+1,j,s);
	def_2(i+1,j-1,s-i);
	return false;
}
int def(int k,int n,int s){
	if(n==0){
		if(s==0) return 1;
		else return 0;
	}
	int a=0;
	for(int i=k;i<=9;++i){
		a+=def(i+1,n-1,s-i);
	}
	return a;
}
main(){
	int s,n;
	while(cin>>n>>s,n||s){
		ans=0;
		cout<<def(0,n,s)<<endl;
		//cout<<ans<<endl;
	}
}