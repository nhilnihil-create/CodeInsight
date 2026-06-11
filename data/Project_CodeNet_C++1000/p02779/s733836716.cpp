#include<iostream>
#include<set>

int main(void){
    std::set<int> s;
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
	int v;
	std::cin >> v;
	if(s.find(v) != s.end()){
	    std::cout << "NO" << std::endl;
	    return 0;
	}
	s.insert(v);
    }
    std::cout << "YES" << std::endl;
    return 0;
}

