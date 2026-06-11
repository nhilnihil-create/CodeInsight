#include <iostream>
#include <vector>

int main(void){
	int a,b,c,d;
	std::vector<int> num;

	while(std::cin >> a >> b >> c >> d){
		num.push_back(a);
		num.push_back(b);
		num.push_back(c);
		num.push_back(d);
	}
	
	int hit,blow;
	for(int i = 0; i < (int)num.size(); i += 8){
		hit = 0, blow = 0;
		for(int j = 0; j < 4; ++j){
			for(int k = -j; k < -j+4; ++k){
				if(k == 0){
					if(num[i+j+4] == num[i+j+k]){
						++hit;
					}
				}else{
					if(num[i+j+4] == num[i+j+k]){
						++blow;
					}
				}
			}
		}
		std::cout << hit << " " << blow << std::endl;
	}

	return 0;
}