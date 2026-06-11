#include <bits/stdc++.h>
using namespace std;
typedef long long       ll;
typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef set<int>        si;

template<typename T> T sgn (T x)      {return x<0? -1:x!=0; }
template<typename T> T gcd (T a, T b) {return a ? gcd (b % a, a) : b; }
//pi=acos(-1)
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define clr(x,v) memset(x,v,sizeof x)
#define forn(i,a,b) for(int i=a;i<b;i++)
#define popcount __builtin_popcount
#define eb emplace_back
#define emp emplace
#define ss second
#define ff first
#define MOD ((int)1e9+7)
#define N ((int)2e5+123)
void reads(string& x){ char kk[N]; scanf("%s",kk); x = kk;}

int ans, m, n;
int a[N], b[N];

void solve(){
    scanf("%d", &n);
    forn(i,0,n){
        scanf("%d %d", a+i, b+i);
    }
    sort(a,a+n);
    sort(b,b+n);
    m = n/2;
    //printf("%d\n", m);
    if(n&1){
        ans = b[m]-a[m]+1;
    }
    else{
        ans = b[m]+b[m-1] - (a[m]+a[m-1]) + 1;
    }
    printf("%d\n",ans);
}

int main(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;//scanf("%d",&t);
    while(t--)solve();
}