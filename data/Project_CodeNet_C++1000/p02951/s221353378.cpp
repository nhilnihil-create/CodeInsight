//MD. HASNAIN ALI (UNSOLVED)
#include <bits/stdc++.h>

#define ll long long
#define pii pair<int,int>

#define distance(a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define MAX3(a,b,c) max(a,max(b,c))
#define SQ(x) ((x) * (x))
#define SWAP(a,b) {        \
                    a=a+b; \
                    b=a-b; \
                    a=a-b; }

using namespace std;

int main()
{
    int a,b,c,d;
    scanf("%d %d %d",&a,&b,&c);
    d=(c-(a-b));
    if(d>=0) printf("%d\n",d);
    else printf("%d\n",0);

    return 0;
}
