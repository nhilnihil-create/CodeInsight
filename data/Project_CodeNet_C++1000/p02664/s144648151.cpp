#include<iostream>
#include<string>

int main(){
	std::string t;
	std::cin >> t;
	int tz = t.size();
	int res = 0;
	for(int i=0; i<tz; i++){
		if(t[i] == '?'){
			t[i] = 'D';
		}
	}
	std::cout << t << std::endl;
	return 0;
}