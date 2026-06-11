#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int getMaxKByO(const vector<int>& counts, const vector<int>& sums, int O) {
    auto pos = lower_bound(counts.begin(), counts.end(), O);
    int pos_idx = pos - counts.begin();
    if (pos_idx == 0) {
        return counts.size();
    } else {
        return counts.size() - pos_idx + sums[pos_idx - 1] / O;
    }
}

int getMaxO(const vector<int>& counts, const vector<int>& sums, int N, int K) {
    int lo_o = 0;
    int hi_o = N / K;
    if (getMaxKByO(counts, sums, hi_o) >= K) {
        return hi_o;
    }

    while (lo_o + 1 < hi_o) {
        int mid_o = (lo_o + hi_o) / 2;
        if (getMaxKByO(counts, sums, mid_o) >= K) {
            lo_o = mid_o;
        } else {
            hi_o = mid_o;
        }
    }
    return lo_o;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    unordered_map<int, int> num_count;
    int max_count = 0;
    for (int num : A) {
        num_count[num] += 1;
        max_count = max(max_count, num_count[num]);
    }

    vector<int> counts;
    counts.reserve(num_count.size());
    for (auto it = num_count.begin(); it != num_count.end(); ++it) {
        counts.push_back(it->second);
    }
    sort(counts.begin(), counts.end());
    vector<int> sums(counts.size());
    for (int i = 0; i < sums.size(); ++i) {
        sums[i] = i == 0 ? counts[i] : counts[i] + sums[i - 1];
    }
    
    for (int K = 1; K <= N; ++K) {
        cout << getMaxO(counts, sums, N, K) << endl;
    }
}