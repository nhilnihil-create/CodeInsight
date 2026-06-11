#include<bits/stdc++.h>
using namespace std;
int main(){

  int h,w,m;
  cin>>h>>w>>m;
int   r[h+1]={0},c[w+1]={0};
  set<pair<int,int>>p;
while(m--){
    int a,b;
    cin>>a>>b;
    p.insert({a,b});
    r[a]++;
    c[b]++;
}
int x=1,y=1;
for(int i=1;i<=h;i++){
    if(r[i]>r[x])
        x=i;
}
for(int i=1;i<=w;i++){
    if(c[i]>c[y])
        y=i;
}
int ans=0;
for(int i=1;i<=w;i++){
    if(p.find({x,i})!=p.end())
        ans=max(ans,r[x]+c[i]-1);
        else
            ans=max(ans,r[x]+c[i]);
}
for(int i=1;i<=h;i++){
    if(p.find({i,y})!=p.end())
        ans=max(ans,r[i]+c[y]-1);
    else
        ans=max(ans,r[i]+c[y]);
}
cout<<ans;
}
