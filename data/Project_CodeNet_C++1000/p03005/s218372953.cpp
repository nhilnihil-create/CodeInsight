#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;scanf("%d%d",&n,&k);
    int l=n-(k-1)-1;
    if(k==1)l=0;
    printf("%d\n",l);
    return 0;
}