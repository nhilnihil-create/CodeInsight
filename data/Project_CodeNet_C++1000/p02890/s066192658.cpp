#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>



int main()
{
    std::ios_base::sync_with_stdio(0);
    std::vector<int> result;
    std::vector<int> B;
    std::vector<int> BS = {0};
    int64_t n;
    std::cin >> n;
    std::map<int, int> M;
    for (int i=0;i<n;++i)
    {
        int a;
        std::cin >> a;
        M[a]++;
    }
    for (auto it : M) B.push_back(it.second);
    std::sort(B.begin(), B.end(), std::greater<int>());
    for (int i=0;i<B.size();++i) BS.push_back(BS.back() + B[i]);

    int last = -1;
    int buff = 0;
    int div = n;
    for (int i=1;i<=n;++i)
    {
        auto it = std::upper_bound(B.begin(), B.end(), div, std::greater<int>());
        int j = std::distance(B.begin(), it);
        int k = (div == 0 ? i : (j + (BS.back()-BS[j]) / div));
        if (k >= i || div == 0) std::cout << div << "\n";
        else { --div; --i; }
    }

    return 0;
}