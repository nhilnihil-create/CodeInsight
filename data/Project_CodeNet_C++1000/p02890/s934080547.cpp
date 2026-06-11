#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n; cin >> n;
    vector<int> as(n, 0);
    vector<int> num_cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
        num_cnt[as[i]]++;
    }

    sort(num_cnt.begin(), num_cnt.end());

    vector<int> dup_cnt(n + 1, 0);

    int num_cnt_idx = 0;
    for (int i = 1; i <= n; i++) {
        dup_cnt[i] = dup_cnt[i - 1];

        while (num_cnt_idx <= n && num_cnt[num_cnt_idx] < i)
        {
            num_cnt_idx++;
        }

        while (num_cnt_idx <= n && num_cnt[num_cnt_idx] == i)
        {
            dup_cnt[i] += num_cnt[num_cnt_idx];
            num_cnt_idx++;
        }
    }

    vector<int> k_to_n(n + 1, 0);
    for (int ni = 1; ni <= n; ni++) {
        int over_cnt = (num_cnt.end() - upper_bound(num_cnt.begin(), num_cnt.end(), ni)) * ni;
        int k = (dup_cnt[ni] + over_cnt) / ni;
        // cout << ni << " : " << dup_cnt[ni] << " - " << over_cnt << " : " << k << endl;
        k_to_n[k] = ni;
    }
    for (int i = n - 1; i >= 1; i--){
        if (k_to_n[i] != 0) {
            continue;
        }
        k_to_n[i] = k_to_n[i+1];
    }
    for (int i = 1; i <= n; i++) {
        cout << k_to_n[i] << endl;
    }

    return 0;
}