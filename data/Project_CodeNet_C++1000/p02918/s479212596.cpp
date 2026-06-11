#include<bits/stdc++.h>
using namespace std;
int n,k,t;
char c1,c2;
int main(){
    scanf("%d%d",&n,&k);
    getchar();
    int ans=n-1;
    for(int i=0;i<n;i++){
        c1=c2;
        c2=getchar();
        if((c1=='L'&&c2=='R')||(c1=='R'&&c2=='L')) ans--; 
    }
    ans+=2*k;
    printf("%d",min(ans,n-1));
    return 0;
}
/*
13 3
LRRLRLRRLRLLR
LRRRLLRRLRLLR
LRRRRRLLLRLLR
LRRRRRRLLLLLR
*/