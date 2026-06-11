#define HAVE_STRUCT_TIMESPEC
#include<bits/stdc++.h>
using namespace std;
int a[17][17],b[17][17];
int xx[17];
int num[17];
int n;
int check(int x){
    memset(num,0,sizeof(num));
    int ans=0;
    int cnt=1;
    while(x){
        if(x&1){
            num[cnt]=1;
            ++ans;
        }
        x/=2;
        ++cnt;
    }
    int flag=0;
    for(int i=1;i<=n;++i){
        if(num[i]){
            for(int j=1;j<=xx[i];++j){
                if(b[i][j]==1&&!num[a[i][j]])
                    flag=1;
                else if(b[i][j]==0&&num[a[i][j]])
                    flag=1;
            }
        }
    }
    if(!flag)
        return ans;
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>xx[i];
        for(int j=1;j<=xx[i];++j){
            cin>>a[i][j]>>b[i][j];
        }
    }
    int lastans=0;
    for(int i=0;i<=(1<<n)-1;++i)
        lastans=max(lastans,check(i));
    cout<<lastans;
    return 0;
}