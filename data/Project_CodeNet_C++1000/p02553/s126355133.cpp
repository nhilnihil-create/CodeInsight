#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){


ll a,b,c,d,ans,t;
while(cin>>a>>b>>c>>d){
ans=a*c;
t=a*d;
ans=max(ans,t);
t=b*c;
ans=max(t,ans);
t=b*d;
ans=max(ans,t);
cout<<ans<<endl;


}





return 0;}

