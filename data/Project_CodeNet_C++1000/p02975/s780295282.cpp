#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <array>

using namespace std;

void re(int& x);

template<class T> void re(std::vector<T>& a);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef vector<int> vi;

int n;

void solve()
{
    re(n);
    vi a(n); re(a);

    vi h(n, -1);

    h[0] = 0;
    for (int i = 2; i != 0; i = (i+2)%n) {
        h[i] = (h[(i+n-2)%n] ^ a[(i+n-1)%n]);
    }

    if ((h[0] ^ h[n-2]) != a[n-1]) {
        ps("No");
        return;
    }

    if (h[1] == -1) {
        h[1] = 0;
        for (int i = 3; i != 1; i = (i+2)%n) {
            h[i] = (h[(i+n-2)%n] ^ a[(i+n-1)%n]);
        }    

        if ((h[1] ^ h[n-1]) != a[0]) {
            ps("No");
            return;
        }   
    }
    
    ps("Yes");
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}

