#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int i,j,k,n,m,c,t,y,mx,x;
    cin>>n>>x>>y;
    if(x>y) swap(x,y);k=y-x-1;//k=max(k,0);
    map<int,int>mp;
    for(i=1;i<n;i++){
        for(j=i+1;j<=n;j++){
            c=j-i;
            c=min(c,abs(i-x)+abs(j-y)+1);
           // c=min(c,abs(i-y)+abs(j-x));
            mp[c]++;
           // cout<<i<<" "<<j<<" ="<<c<<endl;
        }
    }
    for(i=1;i<n;i++){
        printf("%d\n",mp[i]);
    }
    return 0;
}
