#include<bits/stdc++.h>
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define gc getchar()//(p1==p2&&(p2=(p1=buf)+fread(buf,1,size,stdin),p1==p2)?EOF:*p1++)
#define mk make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define IT iterator 
#define vi vector<int>
#define TP template<class o>
#define SZ(a) ((int)a.size())
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int N=2e5+10,size=1<<20,mod=998244353,inf=2e9;

//char buf[size],*p1=buf,*p2=buf;
template<class o> void qr(o &x) {
    char c=gc; x=0; int f=1;
    while(!isdigit(c)){if(c=='-')f=-1; c=gc;}
    while(isdigit(c)) x=x*10+c-'0',c=gc;
    x*=f;
}
template<class o> void qw(o x) {
    if(x/10) qw(x/10);
    putchar(x%10+'0');
}
template<class o> void pr1(o x) {
    if(x<0)x=-x,putchar('-');
    qw(x); putchar(' ');
}
template<class o> void pr2(o x) {
    if(x<0)x=-x,putchar('-');
    qw(x); putchar('\n');
}

bool pd(int x) {
    int n=0;
    while(x) x/=10,n++;
    return n&1;
}

int main() {
    int n,ans=0;
    qr(n);
    for(int i=1;i<=n;i++) ans+=pd(i);
    pr2(ans); return 0;
}