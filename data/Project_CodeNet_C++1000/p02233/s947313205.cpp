#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <array>
#include <complex>
#include <utility>
#include <map>
#include <inttypes.h>


int main(){
	int N;
    
    std::cin >> N;
    int F[100];
    F[0]=F[1]=1;
    for(int i=2;i<=N;i++){
        F[i]=F[i-1]+F[i-2];
    }
    std::cout << F[N]<< std::endl;
    return 0;
}
