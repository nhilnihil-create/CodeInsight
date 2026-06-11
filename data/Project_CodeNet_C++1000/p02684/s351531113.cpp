
#include<bits/stdc++.h>
using namespace std;
const int N = 2* 1e5+5;
typedef long long ll;
ll n,k;
ll a[N];
int main(){
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        int p[n+1],d[n+1],curr=1,turns=0; int vis[n+1]; memset(vis,0,sizeof(vis)); vis[curr]=1;
        p[1]=0; int st,cs; d[0]=1;
        while(true){
                curr=a[curr];
                turns++;
                if(vis[curr]) { cs=turns-p[curr]; st=p[curr]; break; }
                d[turns]=curr;
                vis[curr]=1;
                p[curr]=turns;
        }
        if(k<=st){ cout<<d[k]<<endl; return 0;}
        k-=st;
        k%=cs;
        cout<<d[st+k]<<endl;
}

