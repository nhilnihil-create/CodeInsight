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

void pr(int x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

int n;

void solve()
{
    re(n);
    if ( (n&(n-1)) == 0) {
        ps("No");
        return;
    }

    ps("Yes");
    ps(1, 2);
    ps(2, 3);
    ps(3, n+1);
    ps(n+1,n+2);
    ps(n+2,n+3);

    for (int i = 4; i < n; i+=2) {
        ps(i,i+1);
        ps(i+1,1);
        ps(1,n+i);
        ps(n+i,n+i+1);
    }

    if (n % 2 == 0) {
        int bb = 1<<__lg(n);
        
        ps(n, bb+1);
        int rem = n ^ bb;
        ps(n + rem, 2*n);
    }
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}

