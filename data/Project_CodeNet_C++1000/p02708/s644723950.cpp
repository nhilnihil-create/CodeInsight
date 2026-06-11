#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <climits>


int main(){
    long N,K;
    std::cin >> N >> K;
    long sum=0;
    long plus=1;
    long MOD=1000000000+7;
    for(long i=0; i<=N+1; i++){
        if(K<=i){
            sum+=plus;
            sum%=MOD;
        }
        plus+=(N-i*2);
        plus%=MOD;
        if(plus<0){
            plus+=MOD;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}