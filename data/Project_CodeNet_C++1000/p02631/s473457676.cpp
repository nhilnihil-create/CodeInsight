#include <iostream>
#include <vector>

std::vector<int> bitSum(30,0);

int main(){
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> Bit (N,std::vector<int>(30,0));
    for(int i=0;i<N;i++){
        int a_i;
        std::cin >> a_i;
        for(int j=0;j<30;j++){
            if((1 & a_i >> j) == 1){
                Bit[i][j] ++ ;
                bitSum[j] ++ ;
            }
        }
    }

    for(int i=0;i<N;i++){
        int ans = 0;
        int reverseNum =0;
        for(int j=0;j<30;j++){
            if(Bit[i][j] == 1){
                reverseNum = N - bitSum[j];
            }else{
                reverseNum = bitSum[j];
            }
            if(reverseNum % 2 == 0){
                ans += ((Bit[i][j]) << j);
            }else{
                ans += ((Bit[i][j] ^ 1) << j);
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}

