#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int h,m;
int cal(int h,int m){
    return h*60+m;
}
int main(){
    int ans=0;
    scanf("%d%d",&h,&m);
    ans-=cal(h,m);
    scanf("%d%d",&h,&m);
    ans+=cal(h,m);
    int k;scanf("%d",&k);
    ans=ans-k;
    printf("%d\n",max(ans,0));
    return 0;
}