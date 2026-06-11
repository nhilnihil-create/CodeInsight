#include <iostream>
#include <vector>
#include <cmath>

int main(void){
    int N, D, ans=0;
    std::cin >> N >> D;
    std::vector<std::vector<int>> X(N, std::vector<int>(D));

    for (int i=0; i<N; ++i){
        for (int j=0; j<D; ++j){
            std::cin >> X.at(i).at(j);
        }
    }

    for (int i=0; i<N-1; ++i){
        for (int j=i+1; j<N; ++j){
            int tmp = 0;
            for (int k=0; k<D; ++k){
                tmp += (X.at(i).at(k) - X.at(j).at(k)) * (X.at(i).at(k) - X.at(j).at(k));
            }
            double d = sqrt(tmp);
            if (tmp == (int)d *  (int)d) ++ans;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
