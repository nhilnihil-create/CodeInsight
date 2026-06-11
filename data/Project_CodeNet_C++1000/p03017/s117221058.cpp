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

char s[maxn];
int n,a,b,c,d;

int check(int x,int y) {
    int z=0;
    for(int i=x;i<=y;i++) {
        if(s[i]=='.') z=0;
        else z++;
        if(z>1) return 0;
    }return 1;
}

int main() {
    read(n),read(a),read(b),read(c),read(d);
    scanf("%s",s+1);
    if(c==d) puts("No");
    else if(c<d) puts(check(a,c)&&check(b,d)?"Yes":"No");
    else {
        if(!check(a,c)) puts("No");
        else {
            int aa=0,bb=0,bo=0;
            for(int i=b-1;i<=d+1;i++) {
                if(s[i]=='.') aa++,bb=0;
                else bb++,aa=0;
                if(bb>1) break;
                if(aa>2) {bo=1;break;}
            }
            puts(bo?"Yes":"No");
        }
    }
    return 0;
}
