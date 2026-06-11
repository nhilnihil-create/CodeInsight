#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5;
int L[N] = {}, R[N] = {};
int gd[N] = {};
string str, pre;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, c, k;
    cin >> n >> c >> k;
    cin >> str;
    if (k == 0) {
        int cnto = 0;
        for (const char &c : str)
            cnto += c == 'o';
        if (cnto == c)
            for (int i = 1; i <= n; i++)
                 if (str[i - 1] == 'o')
                    cout << i << '\n';
        return 0;
    }
    k++;
    for (int i = 0; i < k; i++)
        pre.push_back('x');
    str = pre + str + pre;
    for (int i = k; i < n + k + k; i++)
        L[i] = (str[i] == 'o' ? L[i - k] + 1 : L[i - 1]);
    for (int i = n + k - 1; i >= 0; i--)
        R[i] = (str[i] == 'o' ? R[i + k] + 1 : R[i + 1]);
    for (int i = 1; i < n + k; i++)
        gd[i] = L[i] + R[i + k];
    deque<int> deq;
    for (int i = 1; i < n + k; i++) {
        while (!deq.empty() && gd[deq.back()] <= gd[i - 1])
            deq.pop_back();
        deq.emplace_back(i - 1);
        if (deq.front() <= i - k)
            deq.pop_front();
        if (str[i] == 'o' && !deq.empty() && gd[deq.front()] < c)
            cout << i - k + 1 << '\n';
    }
    return 0;
}
