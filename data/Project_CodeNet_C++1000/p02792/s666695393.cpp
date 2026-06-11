/* 
* ID: juryc
* PROG: HandStand2
* LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
int n; cin>>n;
int dig[10][10]; 
memset(dig,0,sizeof(dig));
auto fd=[&](int b){ while((b/10)) b/=10; return b;}  ;
auto ld=[&](int b){ return b%10; };
long long ans=0;
for(int i=1;i<=n;i++) { 
int v1=fd(i),v2=ld(i); 
ans+=2*dig[v2][v1]; 
if(v1==v2) ans++;
dig[v1][v2]++;
}
cout<<ans<<"\n"; 
return 0;
} 
