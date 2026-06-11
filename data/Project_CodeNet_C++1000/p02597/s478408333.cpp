#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char p[200005];
int main()
{
   ll a,b,c,d,k=0;
   cin>>a;
cin>>p;
ll ans=0;
for(int i=0;i<a;i++)
    if(p[i]=='R')
    ans++;
for(int i=0;i<ans;i++)
    if(p[i]=='R')
    k++;

    cout<<ans-k<<endl;
    
    
    return 0;
}
