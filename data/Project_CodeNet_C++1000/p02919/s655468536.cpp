#include<bits/stdc++.h>
using namespace std;
int st[100005];
int main()
{
    int g,t;
    long long x,q,w,e,r,nt,re=0;
    multiset<int>k;
    scanf("%d",&t);
    for(g=0;g<t;g++){
        scanf("%d",&x);
        st[--x]=g;
    }
    k.insert(-1),k.insert(-1),
    k.insert(t),k.insert(t);
    for(g=t-1;g>=0;g--){
        k.insert(st[g]);
        auto z=k.find(st[g]);
        z++, e=*z;
        z++, r=*z;
        z--, z--;
        z--, w=*z;
        z--, q=*z;
        nt=(((r-e)*(st[g]-w))+((w-q)*(e-st[g])));
        re+=(nt*(g+1));
    }
    printf("%lld\n",re);
    return 0;
}
