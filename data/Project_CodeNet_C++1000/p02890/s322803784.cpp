
#include <iostream>
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>

using namespace std;

typedef long long LL;

#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
    int N;
    cin >> N;
    vector<int> hist(N);
    rep(i, N) {
        int a;
        cin >> a;
        ++hist[a-1];
    }

    sort(hist.begin(), hist.end());

    vector<int> s(N+1);  //! s[i] = sum of hist[0..i) 
    for (int i = 1; i <= N; ++i) {
        s[i] = s[i-1] + hist[i-1];
    }

    int ans = N;
    int i = N;
    for (int k = 1; k <= N; ++k) {
        auto check = [&](int c) {
            while (0 < i && c <= hist[i-1]) --i;
            LL sum = c * (N-i) + s[i];
            bool ret = (c * k <= sum);
            return ret;
        };
        while (0 <= ans) {
            if (check(ans)) {
                break;
            } else {
                --ans;
            }
        }
        cout << ans << '\n';
    }
    cout << endl;

    return 0;
}
