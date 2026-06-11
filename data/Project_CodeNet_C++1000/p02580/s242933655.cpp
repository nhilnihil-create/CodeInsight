#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fod(i,a,b) for(int i=a;i>=b;i--)
#define me0(a) memset(a,0,sizeof(a))
#define me1(a) memset(a,-1,sizeof(a))
#define op freopen("in.txt", "r", stdin)
#define op1 freopen("C:\\acm\\Cproj\\in.txt","r",stdin);
#define pr freopen("C:\\acm\\Cproj\\out.txt","w",stdout)
#define pr2 freopen("C:\\acm\\Cproj\\std.txt","w",stdout)
#define pii pair<int,int>
using namespace std;
const int INF = 0x3f3f3f3f;
typedef long long LL;
template <class T>
void read(T &val) { T x = 0; T bz = 1; char c; for (c = getchar(); (c<'0' || c>'9') && c != '-'; c = getchar()); if (c == '-') { bz = -1; c = getchar(); }for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48; val = x * bz; }
const int maxn = 1e6 + 11;
const int mod=1e9+7;
int n,m,x,y,t;

vector<int> col[maxn],row[maxn];
int num[maxn];


int main(){
    int h,w;read(h);read(w);
    read(m);
    fo(i,1,m){
        int x,y;read(x);read(y);
        row[x].push_back(y);
        col[y].push_back(x);
    }
    multiset<int>ms;
    fo(i,1,w) ms.insert(col[i].size()),num[i]=col[i].size();


    int ans = 0;
    fo(i,1,h){
        for(auto to:row[i]){
            ms.erase(ms.lower_bound(num[to]));
            num[to]--;
            ms.insert(num[to]);
        }
        ans = max(ans,(int)row[i].size()+*ms.rbegin());
        for(auto to:row[i]){
            ms.erase(ms.lower_bound(num[to]));
            num[to]++;
            ms.insert(num[to]);
        }
    }
    printf("%d\n",ans);
    return 0;
}