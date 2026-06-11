#include<bits/stdc++.h>
using namespace std;

#define sc1(a)  scanf("%d",&a)

int main(){
    int n,ans=0;
    sc1(n);
    for (int i=n;i>0;i--) {
        if (i/100000>0) false;
        else if (i/10000>0) ans++;
        else if (i/1000>0) false;
        else if (i/100>0) ans++;
        else if (i/10>0) false;
        else ans++;
    }
    printf("%d\n",ans);
    return 0;
}
