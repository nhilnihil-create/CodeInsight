#include<iostream>
#include<array>

int main(){

	std::array<int, 4> A;
	while(std::cin >> A[0] >> A[1] >> A[2] >> A[3]){
		std::array<int, 4> B;
		std::cin >> B[0] >> B[1] >> B[2] >> B[3];
		
		int hit = 0;
		int blow = 0;
		for(int i=0; i<4; ++i){
			if( A[i] == B[i] )
				++hit;
			else
				for(int j=0; j<4; ++j)
					if( A[i] == B[j] )
						++blow;
		}
		std::cout << hit << " " << blow << std::endl;
	}
	return 0;
}