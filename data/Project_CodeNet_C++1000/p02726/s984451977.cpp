#include<bits/stdc++.h>
using namespace std;
int st[2003];
int main()
{
    int g,h,t,q,w,a,b,c,nn;
    scanf("%d %d %d",&t,&q,&w);
    for(g=1;g<t;g++){
        for(h=g+1;h<=t;h++){
            a=h-g;
            b=abs(q-g)+abs(w-h)+1;
            c=abs(q-h)+abs(w-g)+1;
            nn=min(a,min(b,c));
            st[nn]++;
        }
    }
    for(g=1;g<t;g++)
        printf("%d\n",st[g]);
    return 0;
}
