#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,r,d,s,ans=0;
    cin>>l>>r>>d;
    s = l/d;
    s *=d;
    if(s!=l)
        s+=d;
    for(int i=s;i<=r;i+=d)
        ans++;
    cout<<ans<<endl;
}
