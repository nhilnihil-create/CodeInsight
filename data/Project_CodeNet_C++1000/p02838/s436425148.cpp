#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <climits>
int main(void){
    
    long N;
    std::cin >> N;
    long A[300000+1];
    for(long i=1; i<=N; i++){
        std::cin >> A[i];
    }

    long sum=0;
    long one=0,zero=0;
    long MOD = 1000000000+7;
    long shifter=1;
    for(long i=0; i<=60;i++){
        one=0;zero=0;
        for(long j=1; j<=N; j++){
            if((A[j]>>i)&1){
                one++;
            }else{
                zero++;
            }
        }
        long plus=(one*zero);
        plus%=MOD;
        sum+=(plus*shifter)%MOD;
        sum%=MOD;
        shifter*=2;
        shifter%=MOD;
    }
    std::cout << sum << std::endl;
    return 0;
}