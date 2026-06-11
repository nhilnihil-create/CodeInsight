#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[55],b[55],c[55],d[55];
int n,m,q;
int num[12]={0};
int cal(){
    int ret = 0;
    for(int i=0;i<q;i++){
        if(num[b[i]-1]-num[a[i]-1]==c[i])
            ret+=d[i];
    }
    return ret;
}
int dfs(int ind,int maxnum){
    if(ind==n){
        return cal();
    }
    int ret = 0;
    for(int i=maxnum;i<=m;++i){
        num[ind]=i;
        ret = max(ret,dfs(ind+1,max(maxnum,i)));
    }
    return ret;
}
int main()
{
    cin >> n >> m >> q;
    for(int i=0;i<q;i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    cout << dfs(0,1)<<endl;
    return 0;
}
