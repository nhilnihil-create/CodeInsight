#define HAVE_STRUCT_TIMESPEC
#include<bits/stdc++.h>
using namespace std;
int ans[100007];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    if(s[n]=='1'){
        cout<<-1;
        return 0;
    }
    int x=n;
    int flag=0;
    int cnt=0;
    while(1){
        flag=0;
        int r=max(0,x-m);
        for(int i=r;i<x;++i){
            if(s[i]=='0'){
                ans[++cnt]=x-i;
                x=i;
                flag=1;
                break;
            }
        }
        if(x==0||!flag)
            break;
    }
    if(flag)
        for(int i=cnt;i;--i)
            cout<<ans[i]<<" ";
    else
        cout<<-1;
    return 0;
}
