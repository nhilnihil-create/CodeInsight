#include<bits/stdc++.h>
using namespace std;
int h,w;
int n;
pair<int,int>d[300005];
set<int>x;
set<int>y;
int hang[300005],cot[300005];
int check(int xmax,int ymax){
    for(int i=1;i<=h;i++)if(xmax==hang[i])x.insert(i);
    for(int i=1;i<=w;i++)if(ymax==cot[i])y.insert(i);
    long long cnt=0;
    for(int i=1;i<=n;i++){
        if(x.find(d[i].first)!=x.end() && y.find(d[i].second)!=y.end()){
            cnt++;
        }
    }
    return (cnt==1LL*x.size()*y.size());
}
int main(){
    cin>>h>>w>>n;
    for(int i=1;i<=n;i++){
        cin>>d[i].first>>d[i].second;
        hang[d[i].first]++;
        cot[d[i].second]++;
    }
    int xmax=0,ymax=0;
    for(int i=1;i<=h;i++)xmax=max(hang[i],xmax);
    for(int i=1;i<=w;i++)ymax=max(cot[i],ymax);
    cout<<xmax+ymax-check(xmax,ymax);
}
