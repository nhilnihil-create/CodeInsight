// 問題の URL を書いておく
// 

#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

//#define ENABLE_PRINT

#if defined(ENABLE_PRINT)

#define Print(v) \
do {\
    cout << #v << ": " << v << endl; \
}while(0)

#define PrintVec(v) \
do {\
    for(int __i = 0; __i < v.size(); ++__i) \
    { \
        cout << #v << "[" << __i << "]: " << v[__i] << endl; \
    }\
}while(0)

#else

#define Print(v) ((void)0)
#define PrintVec(v) ((void)0)

#endif

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

using ll = int64_t;

int main(int, const char**)
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    vector<int> ans;
    int pos = 0;
    m = min(m, n);
//    cout << s << endl;
    while(pos != n)
    {
//        printf("pos: %d, m: %d\n", pos, m);
        bool invalid = true;
        rep(i, m)
        {
            auto index = m - i;
//            printf(" index: %d\n", index);
            if(s[pos + index] == '0')
            {
                pos += index;
                m = min(n - pos, m);
                ans.push_back(index);
                invalid = false;
                break;
            }
        }
        if(invalid)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(ans.begin(), ans.end());
    rep(i, (int)ans.size())
    {
        cout << ans[i] << endl;
    }
    return 0;
}
