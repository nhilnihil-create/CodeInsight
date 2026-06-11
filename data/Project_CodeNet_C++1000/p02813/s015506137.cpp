#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


int main(void){
    int N, ans;
    std::cin >> N;
    std::vector<int> P(N);
    std::vector<int> Q(N);
    std::vector<int> A(N);
    for (int i=0; i<N; ++i){
        std::cin >> P.at(i);
    }
    for (int i=0; i<N; ++i){
        std::cin >> Q.at(i);
    }
    for (int i=0; i<N; ++i){
        A.at(i) = i + 1;
    }

    std::map<std::vector<int>, int> mp;
    do {
        mp[A] = mp.size();
    } while (next_permutation(A.begin(), A.end()));

    ans = abs(mp[P] - mp[Q]);

    std::cout << ans << std::endl;

    return 0;
}
