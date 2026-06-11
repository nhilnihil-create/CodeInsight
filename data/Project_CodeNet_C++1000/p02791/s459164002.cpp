#include<iostream>

const static int INF = 1001001001;

int main(void){
    int n, p, min, ans = 0;
    min = INF;
    std::cin >> n;
    for(int i = 0; i < n; i++){
	std::cin >> p;
	if(min >= p){
	    min = p;
	    ans++;
	}
    }
    std::cout << ans << std::endl;
    return 0;
}

