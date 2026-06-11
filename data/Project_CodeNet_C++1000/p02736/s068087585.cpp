#include<bits/stdc++.h>
using namespace std;

void read(int &x) {
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';x*=f;
}

void print(int x) {
    if(x<0) putchar('-'),x=-x;
    if(!x) return ;print(x/10),putchar(x%10+48);
}
void write(int x) {if(!x) putchar('0');else print(x);putchar('\n');}

#define lf double
#define ll long long 

#define pii pair<int,int >
#define vec vector<int >

#define pb push_back
#define mp make_pair
#define fr first
#define sc second

#define data asd09123jdf02i3h

#define FOR(i,l,r) for(int i=l,i##_r=r;i<=i##_r;i++)

const int maxn = 1e6+10;
const int inf = 1e9;
const lf eps = 1e-8;
const int mod = 1e9+7;

int n,a[maxn];
char s[maxn];
int fac[maxn];

int check() {
    int ans=0;
    for(int i=1;i<=n;i++)
        if((a[i]&1)&&fac[n-1]-fac[i-1]-fac[n-i]==0) ans^=1;
    return ans;
}

int main() {
    read(n),scanf("%s",s+1);
    for(int i=1;i<=n;i++) a[i]=s[i]-'1';
    for(int i=2;i<=n;i++) if(!(i&1)) fac[i]=fac[i>>1]+1;
    for(int i=1;i<=n;i++) fac[i]+=fac[i-1];
    if(check()) {return puts("1"),0;}
    for(int i=1;i<=n;i++) if(a[i]==1) {puts("0");return 0;}
    for(int i=1;i<=n;i++) a[i]/=2;
    if(check()) puts("2");
    else puts("0");
    return 0;
}
