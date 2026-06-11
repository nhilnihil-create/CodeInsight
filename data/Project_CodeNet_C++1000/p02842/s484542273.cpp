#include <iostream>
#include <vector>
#include <algorithm>

constexpr int INF = 1145141919;

int main(){
	std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    double X_min = (double)N/1.08;
    double X_max = (double)(N+1)/1.08;
    bool flag=false;
    for(int i=X_min; i<=X_max; i++){
        if( N == (int)(i*1.08) ){
            flag=true;
            std::cout << i;
        }
    }

    if(flag==false){
        std::cout << ":(";
    }

    return 0;
}
