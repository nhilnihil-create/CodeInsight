#include <iostream>
#include <vector>
#include <atcoder/dsu>

int main()
{
    int N, Q;
    std::cin >> N >> Q;

    atcoder::dsu forest(N);
    std::vector<int> ans;

    for (int i = 0; i < Q; i++)
    {
        int q, u, v;
        std::cin >> q >> u >> v;
        if (q == 0)
            forest.merge(u, v);
        else
            ans.push_back(forest.same(u, v) ? 1 : 0);
    }

    for (int i = 0; i < ans.size(); i++)
        std::cout << ans[i] << std::endl;
}