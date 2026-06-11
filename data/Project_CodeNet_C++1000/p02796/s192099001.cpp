#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int l[100005];
struct node{
    long long l;
    long long r;
    bool operator<(const node & t)const{
        return r<t.r;
    }
};
node zzz[100005];
int dp[200005]={0};
map<long long,int>mm;
int getnum(long long num){
    return mm[num];
}
int seg[800005];
void _insert(int i,int l,int r,int indx,int num){
    if(l==r){
        seg[i]=num;
        return ;
    }
    int m = (l+r)/2;
    if(indx<=m)
        _insert(i<<1,l,m,indx,num);
    else
        _insert(i<<1|1,m+1,r,indx,num);
    seg[i]=max(seg[i<<1],seg[i<<1|1]);
}
int query(int i,int l,int r,int x,int y){
    if(l>=x&&r<=y)
        return seg[i];
    int m = (l+r)/2;
    int num =0 ;
    if(m>=x)
        num=max(num,query(i<<1,l,m,x,y));
    if(m<y)
        num=max(num,query(i<<1|1,m+1,r,x,y));
    return num;
}
int main()
{
    int n;
    cin >> n;
    int a,x;
    set<long long>vv;
    for(int i=0;i<n;i++){
        cin >>a >> x;
        vv.insert(a-x);
        vv.insert(a+x);
        zzz[i].l=a-x;
        zzz[i].r=a+x;
        //cout << a-x <<endl;
    }
    int cnt = 0 ;
    for(auto num:vv){
        mm[num]=++cnt;
        //cout << num <<  " "<< cnt <<  endl;
    }
    sort(zzz,zzz+n);
    for(int i=0;i<n;i++){
        int num;
        if(getnum(zzz[i].r)==1)
            num=0;
        else
            num = query(1,1,cnt,getnum(zzz[i].r),getnum(zzz[i].r));
        //cout << num <<endl;
        num = max(num,1+query(1,1,cnt,1,getnum(zzz[i].l)));
        _insert(1,1,cnt,getnum(zzz[i].r),num);
    }
    cout << query(1,1,cnt,1,cnt);
    return 0;
}
