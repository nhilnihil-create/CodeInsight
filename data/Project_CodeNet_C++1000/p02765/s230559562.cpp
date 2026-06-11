#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,r;
    cin>>n>>r;
    if(n>=10)printf("%d\n",r);
    else{
        int ans=r+1000-100*n;
        printf("%d\n",ans);
    }
}