#include <bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;

struct point {
    int x,y;
}p[maxn];

map<int,int> xcnt,ycnt;

int main(){
    int H,W,M;cin>>H>>W>>M;
    int maxh=0,maxw=0;
    for(int i=0;i<M;i++){
        int h,w;cin>>h>>w;
        p[i]={h,w};
        xcnt[h]++,ycnt[w]++;
        maxh=max(maxh,xcnt[h]),maxw=max(maxw,ycnt[w]);
    }
    int cnt=0;
    for(int i=0;i<M;i++){
        int h=p[i].x,w=p[i].y;
        if(xcnt[h]==maxh&&ycnt[w]==maxw)
            cnt++;
    }
    //cout<<cnt<<endl;
    int num1=0,num2=0;
    for(auto tmp:xcnt)
        if(tmp.second==maxh)
            num1++;
    for(auto tmp:ycnt)
        if(tmp.second==maxw)
            num2++;
        //cout<<ycnt[i]<<endl;
    //cout<<num1<<' '<<num2<<endl;
    if(num1*num2==cnt) cout<<maxh+maxw-1<<endl;
    else cout<<maxh+maxw<<endl;
    return 0;
}


