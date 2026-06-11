// 問題の URL を書いておく
// https://atcoder.jp/contests/abc158/tasks/abc158_d

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
#include <cstring>

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

const int MaxSLen = 100000 + 1;
const int MaxQueryLen = 2 * 100000 + 1;

char ans[MaxSLen + MaxQueryLen * 2 + 2] = {};

int main(int, const char**)
{
    string s;
    cin >> s;
    int head = MaxQueryLen;
    int tail = head + s.size();
    memcpy(&ans[head], s.c_str(), s.size());
    int q;
    cin >> q;
    int mode = 0;
    rep(i, q)
    {
        int m;
        cin >> m;
        if(m == 1)
        {
            mode = (mode + 1) % 2;
        }
        else
        {
            int f;
            char c;
            cin >> f >> c;
            if((mode == 0 && f == 1) || (mode == 1 && f == 2))
            {
                head--;
                ans[head] = c;
            }
            else
            {
                ans[tail] = c;
                tail++;
            }
        }
    }
    if(mode == 1)
    {
        reverse(&ans[head], &ans[tail]);
    }
    printf("%s\n", &ans[head]);
    return 0;
}
