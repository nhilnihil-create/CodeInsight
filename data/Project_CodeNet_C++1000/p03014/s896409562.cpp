#include<iostream>
#include<vector>

int main(void){
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> s(h);
    for(int i = 0; i < h; i++){
	std::cin >> s[i];
    }
    std::vector<std::vector<int>> da(h, std::vector<int>(w));
    for(int i = 0; i < h; i++){
	int cnt = 0;
	int start = 0;
	for(int j = 0; j < w; j++){
	    if(s[i][j] == '#'){
		for(int k = start; k < j; k++){
		    da[i][k] += cnt;
		}
		// std::cout << std::endl;
		start = j+1;
		cnt = 0;
		continue;
	    }else{
		cnt++;
		if(j == w - 1){
		    for(int k = start; k <= j; k++){
		        da[i][k] += cnt;
		    }
		    
		}
	    }
	}
    }
    // std::cout << std::endl;
    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j++){
    //         std::cout << da[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
    for(int i = 0; i < w; i++){
	int cnt = 0;
	int start = 0;
	for(int j = 0; j < h; j++){
	    if(s[j][i] == '#'){
		for(int k = start; k < j; k++){
		    da[k][i] += cnt;
		}
		start = j + 1;
		cnt = 0;
		continue;
	    }else{
		cnt++;
		if(j == h - 1){
	    	    for(int k = start; k <= j; k++){
	    	        da[k][i] += cnt;
	    	    }
	    	}
	    }
	}
    }
    int max = 0;
    for(int i = 0; i < h; i++){
	for(int j = 0; j < w; j++){
	    max = std::max(max, da[i][j]);
	}
    }
    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j++){
    //         std::cout << da[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    std::cout << max - 1<< std::endl;

    return 0;
}

