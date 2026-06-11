#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;
int main() {
    abdelrahman010
    int n , a[N];
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    vector<int> v;
    int cnt[N] = {};
    for(int i = n;i >= 1;i--) {
        if (a[i]) {
            int c = 0;
            for (int j = i + i; j <= n; j += i)
                c += cnt[j];
            if (c % 2 == 0) {
                v.push_back(i);
                cnt[i]++;
            }
        } else {
            int c = 0;
            for (int j = i + i; j <= n; j += i)
                c += cnt[j];
            if (c % 2) {
                v.push_back(i);
                cnt[i]++;
            }
        }
    }
    cout << v.size() << '\n';
    for(auto &i : v)
        cout << i << " ";
    return 0;
}