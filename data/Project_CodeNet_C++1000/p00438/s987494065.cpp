#include <iostream>
#include <vector>

int main(){
	
	int a,b; //a:street going north and south, b:street going east and west
	while(std::cin >> a >> b){
		if(a == 0 && b == 0) break;
		
		int n; // number of junction under construction
		std::cin >> n;
		
		std::vector<std::vector<int>> junction(b, std::vector<int>(a,0));

		for(int i=0; i<n; ++i){
			int x,y;  //junction under construction
			std::cin >> x >> y;
			junction[y-1][x-1] = -1;
		}
		
		// count school road
		junction[0][0] = 1;
		for(int i=0; i<b; ++i){
			for(int j=0; j<a; ++j){
				if( junction[i][j] != -1){
					if(i != 0 && junction[i-1][j] != -1){
						junction[i][j] += junction[i-1][j];
					}
					if(j != 0 && junction[i][j-1] != -1){
						junction[i][j] += junction[i][j-1];
					}
				}
			}
		}
		
		/*
		for(auto row_it = junction.begin(); row_it != junction.end(); ++row_it){
			for(auto col_it = row_it->begin(); col_it != row_it->end(); ++col_it){
				std::cout << *col_it << std::endl;
			}
		}
		*/
		
		std::cout << junction[b-1][a-1] << std::endl;
	}
	
	return 0;
}