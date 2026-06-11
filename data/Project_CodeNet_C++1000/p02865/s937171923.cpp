#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n==1) puts("0");
    else {
        int ans=n/2;
        if(n&1) printf("%d\n",ans);
        else printf ("%d\n",ans-1);
    }
    return 0;
}
