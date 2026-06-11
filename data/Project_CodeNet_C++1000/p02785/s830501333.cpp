/*
* ID: juryc
* PROG: Fennec vs Monster
* LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
int n; cin>>n; int k; cin>>k;
vector<int> h(n);
for(int& i: h) cin>>i;
sort(h.begin(),h.end()); 
if(k>=n) cout<<0<<endl;
else{
long long ans=0;
for(int i=0;i<n-k;i++)  ans+=h[i]; 
cout<<ans<<"\n";
}
return 0;
}