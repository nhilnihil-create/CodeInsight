//C++
//#pragma comment(linker, "/STACK:102400000,102400000")
//G++
//#define OPENSTACK
#define ONLINE_JUDGE
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cctype>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int MOD = 998244353;
const int N = 3e5 + 1000, M = N;//刻意开大会消耗时间.

int ha[N], hb[N];
int x[N], y[N];

int main()
{
    #ifdef OPENSTACK
    int size = 64 << 20; // 64MB
    char *p = (char*)malloc(size) + size;
    #if (defined _WIN64) or (defined __unix)
        __asm__("movq %0, %%rsp\n" :: "r"(p));
    #else
        __asm__("movl %0, %%esp\n" :: "r"(p));
    #endif
    #endif
    #ifndef ONLINE_JUDGE
        freopen("../put/a.input","r",stdin);
        freopen("../put/a.output","w",stdout);
    #endif
    clock_t c1 = clock();
    //coding here......

    int h, w, m;
    cin >> h >> w >> m;
    int mx = 0, my = 0;

    for(int i = 1; i <= m; i ++){
        cin >> x[i] >> y[i];
        ha[x[i]] ++, mx = max(mx, ha[x[i]]);
        hb[y[i]] ++, my = max(my, hb[y[i]]);
    }
    
    LL t1 = 0, t2 = 0, t = 0;
    for(int i = 1; i <= h; i ++) if(ha[i] ==  mx) t1 ++;
    for(int i = 1; i <= w; i ++) if(hb[i] ==  my) t2 ++;

    t = t1 * t2;
    for(int i = 1; i <= m; i ++){
        if(ha[x[i]] == mx && hb[y[i]] == my) t --;
    }

    if(t) cout << mx + my << endl;
    else cout << mx + my - 1 << endl;
    //finish here......
    #ifndef ONLINE_JUDGE
        std::cerr << "Time:" << clock() - c1 << "ms" << std::endl;
    #endif
    #ifdef OPENSTACK
        exit(0);
    #else
        return 0;
    #endif
}