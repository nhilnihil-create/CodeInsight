#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
    int A, B, M, ans=200001;
    std::cin >> A >> B >> M;
    std::vector<int> a(A);
    std::vector<int> b(B);
    for (int i=0; i<A; ++i){
        std::cin >> a.at(i);
    }
    for (int i=0; i<B; ++i){
        std::cin >> b.at(i);
    }

    for (int i=0; i<M; ++i){
        int x, y, c, tmp;
        std::cin >> x >> y >> c;
        tmp = a.at(x - 1) + b.at(y - 1) - c;
        if (ans > tmp) ans = tmp;
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    if (ans > a.at(0) + b.at(0)){
        ans = a.at(0) + b.at(0);
    }

    std::cout << ans << std::endl;

    return 0;
}
