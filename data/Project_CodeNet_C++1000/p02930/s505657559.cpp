#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=505;
int mp[maxn][maxn];
void f(int l,int r,int deep){
    int s=r-l+1;
    if(s==2){
        mp[l][r]=deep;
        return;
    }
    if(s==1){
        return;
    }
    int s1=s/2,s2=s-s1;//s1<=s2
    for(int i=l;i<=l+s1-1;i++){
        for(int j=l+s1;j<=r;j++){
//            printf("i=%d j=%d\n",i,j);
            mp[i][j]=deep;
        }
    }
    f(l,l+s1-1,deep-1);
    f(l+s1,r,deep-1);
    return;
}
int main(){
    int n;
    cin>>n;
    int nn=n;
    int maxc=1;
    while(nn>2){
        nn=(nn+1)/2;
        maxc++;
    }
//    printf("maxc=%d\n",maxc);
    f(1,n,maxc);
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            printf("%d ",mp[i][j]);
        }
        printf("\n");
    }
}







