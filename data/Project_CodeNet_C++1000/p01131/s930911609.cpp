#include<iostream>
#include<string>

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
	int n;
	int code;
	int num;
	char key[11][7] = {
			{},
			{'.',',','!','?',' '},
			{'a','b','c'},
			{'d','e','f'},
			{'g','h','i'},
			{'j','k','l'},
			{'m','n','o'},
			{'p','q','r','s'},
			{'t','u','v'},
			{'w','x','y','z'},
	};

	std::cin >> n;
	std::string str;

	rep(i,n){
		code = 0;
		num = 0;
		std::cin >> str;
		rep(j,(int)str.size()){
			if(str[j] != '0'){
				num++;
			}else{
				if(j > 0 && str[j-1] != '0'){
					code = str[j-1]-'0';
					if(code == 1){
						std::cout << key[code][(num-1)%5] << std::flush;
					}else if(code == 7 || code == 9){
						std::cout << key[code][(num-1)%4] << std::flush;
					}else{
						std::cout << key[code][(num-1)%3] << std::flush;
					}
					code = 0;
					num = 0;
				}
			}
		}
		std::cout << std::endl;
	}
	return 0;
}