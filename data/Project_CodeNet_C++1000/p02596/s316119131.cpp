#include <iostream>
#include<cstring>

#define MAXN 1000007
using namespace std;
bool vis[MAXN];

int main()
{
    int ans=-1;
    int now=7;
    int k;
    cin>>k;
    vis[now%k]=1;
    memset(vis,0,sizeof vis);
    if(now%k==0) {
        cout << "1\n";
    } else {
        int i=2;
        while(now) {
            now=(now*10+7)%k;
            if(vis[now]) break;
            else if(now==0) {ans=i; break;}
            i++;
            vis[now]=1;
        }
        cout << ans << '\n';
    }
}
