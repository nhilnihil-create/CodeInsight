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

#define pii pair<int,int >
#define vec vector<int >

#define pb push_back
#define mp make_pair
#define fr first
#define sc second

#define FOR(i,l,r) for(int i=l,i##_r=r;i<=i##_r;i++)

const int maxn = 1e6+10;
const int inf = 1e9;
const lf eps = 1e-8;
const int mod = 1e9+7;

int n,t[maxn];

int main() {
    read(n);
    for(int i=0;i<=20;i++) if((1<<i)==n) return puts("No"),0;
    puts("Yes");
    printf("%d %d\n",1,2);
    printf("%d %d\n",2,3);
    printf("%d %d\n",3,1+n);
    printf("%d %d\n",1+n,2+n);
    printf("%d %d\n",2+n,3+n);
    for(int i=4;i<=n-!(n&1);i++) printf("%d %d\n",1+n,i&1?i:i+n);
    for(int i=4;i<=n-!(n&1);i++) printf("%d %d\n",i&1?i:i+n,i&1?(i^1):(i^1)+n);
    if(!(n&1)) {
        for(int i=1;i<=n;i++) {
            if((n^1^i)<i) {
                int a=i,b=n^1^i;
                if(!(a&1)) a+=n;if(!(b&1)) b+=n;
                printf("%d %d\n",a,n);
                printf("%d %d\n",b,n<<1);
                break;
            }
        }
    }
    return 0;
}
