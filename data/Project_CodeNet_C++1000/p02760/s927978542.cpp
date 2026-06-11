#include<iostream>
#include<vector>
#include<set>

int main(void){
    std::vector<std::vector<int>> a(3);
    std::set<int> b;
    for(int i = 0; i < 3; i++){
	a[i].resize(3);
	for(int j = 0; j < 3; j++){
	    std::cin >> a[i][j];
	}
    }
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
	int tmp;
	std::cin >> tmp;
	b.insert(tmp);
    }

    bool flag;
    for(int i = 0; i < 3; i++){
	flag = 1;
	for(int j = 0; j < 3; j++){
	    if(b.find(a[i][j]) == b.end()){
		flag = 0;
		break;
	    }
	}
	if(flag == 1){
	    std::cout << "Yes" << std::endl;
	    return 0;
	}
    }

    for(int i = 0; i < 3; i++){
	flag = 1;
	for(int j = 0; j < 3; j++){
	    if(b.find(a[j][i]) == b.end()){
		flag = 0;
		break;
	    }
	}
	if(flag == 1){
	    std::cout << "Yes" << std::endl;
	    return 0;
	}
    }

    for(int i = 0; i < 3; i++){
	flag = 1;
	if(b.find(a[i][i]) == b.end()){
	    flag = 0;
	    break;
	}
    }
    if(flag == 1){
	std::cout << "Yes" << std::endl;
	return 0;
    }

    for(int i = 0; i < 3; i++){
	flag = 1;
	if(b.find(a[i][2-i]) == b.end()){
	    flag = 0;
	    break;
	}
    }
    if(flag == 1){
	std::cout << "Yes" << std::endl;
	return 0;
    }

    std::cout << "No" << std::endl;
    return 0;
}

