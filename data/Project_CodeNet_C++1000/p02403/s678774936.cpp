#include<iostream>
#include<vector>
std::vector<std::vector<int>> vec;
int x[2];
int main(){
	do{
		std::cin>>x[0]>>x[1];
		if(x[0]!=0 && x[1]!=0)vec.push_back(std::vector<int>{x[0],x[1]});
	}while(x[0]!=0 && x[1]!=0);
	for(auto v:vec){
		for(int i=0;i<v[0];++i){
			std::string str(v[1],'#');
			std::cout<<str<<std::endl;
		}
		std::cout<<std::endl;
	}
	return 0;
}