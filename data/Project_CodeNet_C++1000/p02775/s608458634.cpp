#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<string>
#define ls k<<1,l,mid
#define rs k<<1|1,mid+1,r
#define mp(x,y) make_pair(x,y)
#define r(x) read(x)
#define rrr(x,y,z) read(x);read(y);read(z)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
typedef long long LL;
typedef pair<int,int> pt;
const int N=1e6+5;
const int M=2e3+5;
const int INF=0x7fffffff;
const int mod=1e9+7;
const int bb=18;
const double eps=1e-10;
const double pi=acos(-1);
int n,m;
char str[N];
int f[N+100];
map<string,int> mm;
vector<string> v;
template<class T>
inline void read(T &x)
{
    char c; x=1;
    while((c=getchar())<'0'||c>'9') if(c=='-') x=-1;
    T res=c-'0';
    while((c=getchar())>='0'&&c<='9') res=res*10+c-'0';
    x*=res;
}
int main()
{
    scanf("%s",str+1);
    LL ans=0;
    int len=strlen(str+1);
    FOR(i,1,len){
        f[i]=str[len-i+1]-'0';
    }
    FOR(i,1,len+15){
        if(f[i]>=10){
            f[i]-=10;
            f[i+1]++;
        }
        if(f[i]>=6){
            ans+=10-f[i];
            f[i+1]++;
        }
        else if(f[i]==5){
            ans+=5;
            if(f[i+1]>=5){
                f[i+1]++;
            }
        }
        else ans+=f[i];
    }
    cout<<ans<<endl;
    return 0;
}
