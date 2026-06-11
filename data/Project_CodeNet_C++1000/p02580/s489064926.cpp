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
const int N = 3e5 + 10, M = N;//刻意开大会消耗时间.

int ha[N], hb[N];

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

    // 难点是哈希查找该点是否真的存在.
    unordered_map<int, unordered_set<int>> hash;
    unordered_map<int, vector<int>> row;
    unordered_map<int, vector<int>> line;
    int max1 = 0, max2 = 0;
    // 最大值的时候相等, 但是如何找到是否没有该点.
    for(int i = 1; i <= m; i ++){
        int a, b;
        cin >> a >> b;
        hash[a].insert(b);

        ha[a] ++;
        if(ha[a] > max1) max1 = ha[a], row[max1].push_back(a);
        else if(ha[a] == max1) row[max1].push_back(a);
        hb[b] ++;
        if(hb[b] > max2) max2 = hb[b], line[max2].push_back(b);
        else if(hb[b] == max2) line[max2].push_back(b);
    }

    bool flag = false;
    vector<int> x1 = row[max1], y1 = line[max2];
    for(auto c : x1){
        for(auto s : y1)
            if(hash.count(c) == 0 || hash[c].count(s) == 0) {
                cout << max1 + max2 << endl, flag = true;
                break;
            }
        if(flag) break;
    }

    if(!flag) cout << max1 + max2 - 1 << endl;

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
