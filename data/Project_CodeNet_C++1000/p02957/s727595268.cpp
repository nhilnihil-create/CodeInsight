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
    int a,b,c;
    double d;
    scanf("%d %d",&a,&b);
    d=(a+b)/2.0;
    c=(a+b)/2.0;
    if(c==d) printf("%d\n",c);
    else printf("IMPOSSIBLE\n");

    return 0;
}
