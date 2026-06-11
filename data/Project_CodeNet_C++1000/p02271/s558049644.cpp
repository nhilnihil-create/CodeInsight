#include<iostream>
int n,q;
int A[20],T[200];
bool dfs(int i,int tgt){
	if(i==n)return tgt==0;
	else if(dfs(i+1,tgt))return true;
	else if(dfs(i+1,tgt-A[i]))return true;
}
int main(){
	std::cin>>n;
	for(int k=0;k<n;k++){
		std::cin>>A[k];
	}
	std::cin>>q;
	for(int j=0;j<q;j++){
		std::cin>>T[j];
		if(dfs(0,T[j])){
			std::cout<<"yes\n";
		}
		else std::cout<<"no\n"; 
	}
	return 0;
}