#include <bits/stdc++.h>
#define N 300005
using namespace std;
int x,y,a,b,c,nx,ny,cnt;
long long ans;
struct node{int cl,val;}p[N];
bool cmp(const node &a,const node &b){return a.val>b.val;}
int main(){
    cin>>x>>y>>a>>b>>c;
    for(int i=1;i<=a;i++)cin>>p[i].val,p[i].cl=1;
    for(int i=a+1;i<=a+b;i++)cin>>p[i].val,p[i].cl=2;
    for(int i=a+b+1;i<=a+b+c;i++)cin>>p[i].val,p[i].cl=3;
    sort(p+1,p+1+a+b+c,cmp);
    for(int i=1;i<=a+b+c;i++){
        if(p[i].cl==1){
            if(nx==x)continue;
            nx++;
        }else if(p[i].cl==2){
            if(ny==y)continue;
            ny++;
        }
        cnt++;
        ans+=p[i].val;
        if(cnt==x+y)break;
    }
    cout<<ans<<endl; 
    return 0;
}