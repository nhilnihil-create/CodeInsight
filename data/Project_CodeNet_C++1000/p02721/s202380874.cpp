#include <iostream>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>
#include <tuple>

using namespace std;
mt19937_64 rng(58);

vector<int> arrange(int n, int k, int c, string s) {
    // greedy
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o' && (pos.size() == 0 || pos[pos.size() - 1] < i - c))
            pos.push_back(i);
        if (pos.size() == k) break;
    }
    return pos;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k, c;
    string s;
    cin >> n >> k >> c;
    cin >> s;

    // find the leftmost arangement and the rightmost arrangement
    vector<int> left = arrange(n, k, c, s);
    reverse(s.begin(), s.end());
    vector<int> right = arrange(n, k, c, s);
    for (int i = 0; i < k; i++) right[i] = n - 1 - right[i];
    reverse(right.begin(), right.end());
    for (int i = 0; i < k; i++) {
        if (left[i] == right[i])
            cout << left[i] + 1 << endl;
    }
}