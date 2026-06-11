#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
int n;
std::vector<std::pair<std::string,int>> cards;

void regcards(std::string str,int x){
	cards.push_back(std::make_pair(str,x));
}
int main(){
	for(int i=0;i<4;++i){
		for(int j=1;j<=13;++j){
			switch(i){
				case 0:
					regcards("S",j);
				break;
				case 1:
					regcards("H",j);
				break;
				case 2:
					regcards("C",j);
				break;
				case 3:
					regcards("D",j);
				break;
			}
		}
	}
	std::cin>>n;
	for(int i=0;i<n;++i){
		std::string str;
		int x;
		std::cin>>str>>x;
		for(auto it=cards.begin();it<cards.end();++it){
			if(*it==std::make_pair(str,x))cards.erase(it);
		}
	}
	if(cards.empty()){
		return 0;
	}
	for(auto v:cards){
		std::cout<<v.first<<" "<<v.second<<std::endl;
	}
	return 0;
}