// 問題の URL を書いておく
// 

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <bitset>
#include <numeric>
using namespace std;

//#define ENABLE_PRINT

template<typename T>
T Input()
{
    T v;
    cin >> v;
    return v;
}

template<typename T>
vector<T> InputVector(int n)
{
    vector<T> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    return v;
}

template<typename T>
void InputArray(T* begin, int n)
{
    for(int i = 0; i < n; ++i)
    {
        cin >> begin[i];
    }
}

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

int main(int, const char**)
{
    int s, w;
    cin >> s >> w;
    cout << (w >= s ? "unsafe" : "safe") << endl;
    return 0;
}
