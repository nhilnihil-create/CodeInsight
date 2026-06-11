#include <bits/stdc++.h>

using namespace std;
#define gc getchar()
#define re register
inline int read()
{
    re int x(0);re char c(gc);
    while(c>'9'||c<'0')c=gc;
    while(c<='9'&&c>='0')x=x*10+c-48,c=gc;
    return x;
}

int n;
const int N=1e6+10;
void P(int x,int y){cout<<x<<" "<<y<<'\n';}

int main()
{
    n=read(); int m=1;
    while (m<n) m<<=1;
    if (n<3||m==n) {
        puts("No");
        return 0;
    }
    puts("Yes");
    P(1,n+2); P(n+2,3);
    P(3,n+1); P(n+1,2);
    P(2,n+3);
    for (int i=4;i<n;i+=2) {
        P(i,n+1); P(i,n+i+1);
        P(i+1,n+1); P(n+i,i+1);
    }
    if (!(n&1))
    {
        for (int i=2;i<n;++i) {
            if ((n^(i^1))<n) {
                int a=i;
                int b=n^i^1;
                P(n,a); P(n+n,b);
                break;
            }
        }
    }
    return 0;
}
