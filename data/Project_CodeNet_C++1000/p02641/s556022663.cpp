#include <iostream>
#include <map>
#define For(i,x,y) for(register int i=(x); i<=(y); i++)
using namespace std;
map<int,int>vis;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,x,temp;
    cin>>x>>n;
    For(i,1,n)cin>>temp,vis[temp]=1;
    int ans=0,i=x,j=x;
    while(1)
    {
        if(vis[i])i--;
        else
        {
            ans=i;
            break;
        }
        if(vis[j])j++;
        else
        {
            ans=j;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}