#pragma GCC optimize (3)
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>*/
//#include<ext/rope>
#define ll long long
#define ull unsigned long long
#define INFI 2147483647
#define INFL 9223372036854775807
#define INFU 18446744073709551615
#define maxn 1005
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
const double PI=acos(-1.0);
const double eps=1e-6;
int a[maxn],sta[maxn],dp[maxn][5000];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
template<typename T> void debug(T x)
{
    cout<<"value="<<x<<endl;
    return;
}
signed main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n=read(),m=read();
    for(int i=1;i<=m;i++){
        a[i]=read();
        int b=read();
        for(int j=1;j<=b;j++){
            int c=read();
            c=1<<(c-1);
            sta[i]|=c;
        }
    }
    for(int i=0;i<=m;i++) for(int j=1;j<(1<<n);j++) dp[i][j]=100000001;
    for(int i=1;i<=m;i++){
        for(int j=0;j<(1<<n);j++){
            dp[i][j|sta[i]]=min(dp[i][j|sta[i]],dp[i-1][j]+a[i]);
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
        }
    }
    if(dp[m][(1<<n)-1]==100000001) printf("-1\n");
    else printf("%d\n",dp[m][(1<<n)-1]);
	return 0;
}
