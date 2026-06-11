#include <bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
struct point {
    int x,y;
}p[maxn];
map<int,int> xcnt,ycnt;
signed main(void){
    int n,m,k;
    cin>>n>>m>>k;
    int x,y,maxr=0,maxc=0;
    for(int i=0;i<k;i++){
        cin>>x>>y;
        p[i]={x,y};
        xcnt[x]++,ycnt[y]++;
        maxr=max(maxr,xcnt[x]),maxc=max(maxc,ycnt[y]);
    }
    int num1=0,num2=0;
    for(auto tmp:xcnt)
		if(tmp.second==maxr)
			num1++;
    for(auto tmp:ycnt)
		if(tmp.second==maxc)
			num2++;
    int cnt=0;
    for(int i=0;i<k;i++){
        x=p[i].x,y=p[i].y;
        if(xcnt[x]==maxr&&ycnt[y]==maxc)cnt++;
    }
    if(cnt==num1*num2)
		cout<<(maxc+maxr-1)<<endl;
    else
		cout<<(maxc+maxr)<<endl;
    return 0;
}