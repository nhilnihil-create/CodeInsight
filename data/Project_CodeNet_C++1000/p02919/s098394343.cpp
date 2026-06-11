#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
 
#define INIT() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define rFor(i,t,s) for (int i = (t); i >= (s); --i)
#define ForLL(i, s, t) for (LL i = LL(s); i <= LL(t); ++i)
#define rForLL(i, t, s) for (LL i = LL(t); i >= LL(s); --i)
#define foreach(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)
#define rforeach(i,c) for (__typeof(c.rbegin()) i = c.rbegin(); i != c.rend(); ++i)
 
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
 
#define LOWBIT(x) ((x)&(-x))
 
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define UNIQUE(x) x.erase(unique(x.begin(), x.end()), x.end())
#define REMOVE(x, c) x.erase(remove(x.begin(), x.end(), c), x.end()); // ?? x ?????? c 
#define TOLOWER(x) transform(x.begin(), x.end(), x.begin(),::tolower);
#define TOUPPER(x) transform(x.begin(), x.end(), x.begin(),::toupper);
 
#define ms0(a) memset(a,0,sizeof(a))
#define msI(a) memset(a,inf,sizeof(a))
#define msM(a) memset(a,-1,sizeof(a))

#define MP make_pair
#define PB push_back
#define ft first
#define sd second
 
typedef long long LL;

const double EPS = 1e-8;
const LL inf = 0x7fffffff;
const LL infLL = 0x7fffffffffffffffLL;
const LL mod = 1e9 + 7;
const int maxN = 1e5 + 7;
const LL ONE = 1;
const LL evenBits = 0xaaaaaaaaaaaaaaaa;
const LL oddBits = 0x5555555555555555;

int N;
int P[maxN];     // P数组为1~N的一组排列 
int pos[maxN];     // pos[i]为i在P数组中的位置 
int leftFirstMaxPos[maxN];     // leftFirstMaxPos[i]为i位置的数左边第一个比i大的数的位置,没有则为0
int rightFirstMaxPos[maxN]; // rightFirstMaxPos[i]为i位置的数右边第一个比i大的数的位置,没有则为N+1 
LL ans = 0; 

int main(){
    //freopen("MyOutput.txt","w",stdout);
    //freopen("input.txt","r",stdin);
    //INIT();
    scanf("%d", &N);
    For(i, 1, N) {
        scanf("%d", &P[i]);
        pos[P[i]] = i; 
        // 后面是从1开始枚举,而1是最小的,所以1的左右最近大正好是相邻的两个数 
        leftFirstMaxPos[i] = i - 1;
        rightFirstMaxPos[i] = i + 1;
    }
    
    // 计算每个数i为第二大的时候对答案的贡献 
    For(i, 1, N) {
        int Lpos1 = leftFirstMaxPos[pos[i]];     // i左边第一个比他大的数的位置 
        int Lpos2 = leftFirstMaxPos[Lpos1];        // i左边第二个比他大的数的位置 
        int Rpos1 = rightFirstMaxPos[pos[i]];    // i右边第一个比他大的数的位置 
        int Rpos2 = rightFirstMaxPos[Rpos1];        // i右边第二个比他大的数的位置 
        
        if(Lpos1 != 0) ans += ONE * i * (Lpos1 - Lpos2) * (Rpos1 - pos[i]);
        if(Rpos1 != N + 1) ans += ONE * i * (pos[i] - Lpos1) * (Rpos2 - Rpos1);
        
        // 更新 
        /*
            例如这个片段:
                  1 2 3 4 5 6 7 
                P 6 3 1 2 5 4 7
                此时以i = 1为例
                本来leftFirstMaxPos[4] = 3, rightFirstMaxPos[2] = 3的
                计算完i = 1的贡献之后, leftFirstMaxPos[4] = 2, rightFirstMaxPos[2] = 4
                这一步更新相当于把1给砍掉了,剩下的数中2又是最小的数,于是2的左右最近大又正好是相邻的两个数 
                没错,非常像链表删除一个值的操作 
                leftFirstMaxPos就相当于静态链表的前驱数组
                rightFirstMaxPos就相当于静态链表的后继数组 
        */ 
        leftFirstMaxPos[Rpos1] = Lpos1;
        rightFirstMaxPos[Lpos1] = Rpos1;
    }
    
    printf("%lld", ans);
    return 0;
}