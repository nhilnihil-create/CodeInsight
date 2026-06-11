#include <bits/stdc++.h>
#define sp putchar(' ')
#define en putchar('\n')
#define MOD(x) ((((x)%Mod)+Mod)%Mod)
const int MAXN = 500005 ;
using namespace std ;
class Union_Find_Set
{
static const int N = 2000005;
public:
    int tot/**现有的集合数量*/,cnt[N]/**每个集合有多少人*/,fa[N] ;
    void clear(int n)
    {
        tot = n; ///开始没有合并的时候,每个都是单独的集合.
        iota(fa,fa+n+1,0) ; fill_n(cnt,n+1,1) ;
    }
    int find(int x) ///找x的根
        {return x == fa[x]?x:fa[x] = find(fa[x]) ;}
    int count(int x)///得到元素x所在的集合的人数
        {return cnt[find(x)] ;}
    int size() {return tot ;}
    bool is_same(int a,int b)///判断是不是在同一个集合
        {return find(a)==find(b);}
    int merge(int a,int b)
    {///合并两个集合
        a = find(a);b = find(b) ;
        if(a != b) {
            fa[b] = fa[a] ; cnt[a] += cnt[b];
            -- tot ;
        }
        return tot ;
    }
}S;

int n , m ;
int main()
{
    ios::sync_with_stdio(false) ;
    while(cin >> n >> m) {
        S.clear(n + 3) ;
        for(int i = 0;i < m; ++i) {
            int u,v ;
            cin >> u >> v ;
            S.merge(u, v) ;
        }
        int ans = 0 ;
        for(int i = 1;i <= n; ++ i) {
            ans = max(ans, S.count(i)) ;
        }
        cout << ans << endl ;
    }
}
