#include <iostream>
#include <vector>
#include <cmath>
#define INF 10000000000
int main(){
    int N,K;
    std::cin >> N >> K;
    std::vector<int> Log(N);
    int target = 0;
    for(int i=0;i<N;i++){
        std::cin >> Log[i];
        if(Log[i] > target){
            target = Log[i];
        }
    }

    int t_max = target,t_min = 0;
    int ans = target;
    while(t_max - t_min > 1) {
        int totalCut = 0;
        for (int i = 0; i < N; i++) {
            if (totalCut > K) {
                break;
            }
            if(Log[i] != target) {
                totalCut += std::ceil(Log[i] / target);
            }
        }


        if (totalCut <= K) {
            t_max = target;
            ans = target;
        } else {
            t_min = target;
            ans = target + 1;
        }
        target = std::ceil((t_max + t_min) / 2);
    }

    std::cout << ans;

    return 0;
}



