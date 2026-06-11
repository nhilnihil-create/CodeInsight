#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>
using namespace std;
#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
#define ull unsigned long long
const int maxn = 2e5+10;
const ll mod=1e9+7;
#define MAXN 40100
ll gcd(ll T, ll b) { return b == 0 ? T : gcd(b, T % b); }
ll lcm(ll T, ll b) { return T / gcd(T, b) * b; }
ll mul(ll a,ll b, ll c) {
    ll ans = 0;
    while(b) {
        if(b&1) {
            ans= (ans+a)%c;
            b--;
        }
        b>>=1;
        a=(a+a)%c;
    }
    return ans;
}
 
ll powmod(ll a,ll b,ll c) {
    ll ans = 1;
    while(b) {
        if(b&1) {
            ans = mul(ans,a,c);
            b--;
        }
        b>>=1;
        a=mul(a,a,c);
    }
    return ans ;
}
 
ll exgcd(ll a,ll b,ll &x,ll &y) {
    if(b==0)
    {
        x=1;y=0;
        return a; 
    }
    ll r=exgcd(b,a%b,x,y);
    ll temp=y;
    y=x-(a/b)*y;
    x=temp;
    return r;
}

const ll INF = 0x3f3f3f3f3f3f3f3f;
int pre[maxn];
int siz[maxn];
int ans;
void init() {
    for(int i=0;i<maxn;i++) {
        pre[i]=i;
        siz[i]=1;
    }
}
int find(int x) {
    while(x!=pre[x]) {
        pre[x]=pre[pre[x]];
        x=pre[x];
    }
    return x;
}
void join(int x,int y) {
    int fx=find(x),fy=find(y);
    if(fx!=fy) {
        pre[fx]=fy;
        siz[fy]+=siz[fx];
        if(siz[fy]>ans) {
            ans=siz[fy];
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    init();
    ans=1;
    while(m--) {
        int x,y;
        cin>>x>>y;
        join(x,y);
        // join(y,x);
    }
    cout<<ans<<endl;

    return 0;
}





