#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

string S;

int main() {
    cin >> S;

    // R, L, R, L

    // R: 0
    // L: 1 とする
    int current = 0;
    int cnt = 0;

    vector<ll> nums;

    for (int i = 0; i < S.size(); i++) {
        int judge = 0;
        if (S[i] == 'L') judge = 1; 

        if (judge == current) {
            cnt++;
        } else {
            nums.push_back(cnt);

            current = 1 - current; 
            cnt = 1;
        }
    }
    if (cnt != 0) nums.push_back(cnt);

    // for (int i = 0; i < nums.size(); i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;

    vector<ll> v(S.size(), 0);
    
    // idx: 0, 2, 4... -> R
    // idx: 1, 3, 5... -> L
    int start_pos = 0;

    // RL の組みづつ計算
    for (int i = 0; i < nums.size(); i += 2) {
        // R の奇数
        int r_odd = (nums[i] + 1) / 2;
        // L の偶数
        int l_even = nums[i + 1] / 2;

        // R の偶数
        int r_even = nums[i] / 2;
        // L の奇数
        int l_odd = (nums[i + 1] + 1) / 2;

        int left = r_odd + l_even;
        int right = r_even + l_odd;

        // cout << left << " " << right << endl;
        start_pos += nums[i] - 1;

        // v に代入
        v[start_pos] = left;
        v[start_pos + 1] = right;

        start_pos += nums[i + 1] + 1;
    } 

    rep(i, v.size()) {
        cout << v[i] << " ";
    }
    cout << endl;
}