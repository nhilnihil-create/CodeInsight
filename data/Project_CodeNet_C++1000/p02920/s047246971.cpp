#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;

    int total = 1 << N;
    std::vector<int> S(total);
    for (int i=0; i<total; ++i) {
        std::cin >> S[i];
    }
    std::sort(S.begin(), S.end(), std::greater<int>());

    // HPのヒストグラム (HP降順)
    std::vector<int> hp;
    int prev = -1;
    int count = 0;
    for (int i=0; i<total; ++i) {
        if (prev == S[i]) {
            count += 1;
        } else {
            if (count > 0) {
                hp.push_back(count);
            }
            count = 1;
            prev = S[i];
        }
    }
    hp.push_back(count);

    std::vector<int> trees(N+1, 0);
    trees[N] = 1;

    auto findTree = [&]() {
        for (int j=N; j>=0; --j) {
            if (trees[j] > 0) {
                trees[j] -= 1;
                return j;
            }
        }
        return -1;
    };

    bool ok = true;
    for (int i=0; i<hp.size(); ++i) {
        std::vector<int> queue;
        int pop = hp[i];
        for (int ii=0; ii<pop; ++ii) {
            int t = findTree();
            if (t == -1) {
                ok = false; break;
            }
            queue.push_back(t);
        }
        if (!ok) break;
        for (int q=0; q<queue.size(); ++q) {
            for (int t=0; t<queue[q]; ++t) {
                trees[t] += 1;
            }
        }
    }

    std::cout << (ok ? "Yes" : "No") << std::endl;
    return 0;
}