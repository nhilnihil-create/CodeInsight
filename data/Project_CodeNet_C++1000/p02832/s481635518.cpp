#include<iostream>
#include<vector>

int main(){
  	int n;
  	std::cin >> n;
  	std::vector<int> a(n);
  	int count = 1;
  	int wreck = 0;
  	for(auto&e : a){
      	std::cin >> e;
      	if(e!=count){
          	wreck++;
        }else{
          	count++;
        }
    }
  	if(count==1){
      	std::cout << -1 << "\n";
    }else{
      	std::cout << wreck << "\n";
    }
  	return 0;
}