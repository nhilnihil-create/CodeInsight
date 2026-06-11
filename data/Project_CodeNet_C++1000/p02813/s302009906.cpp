/* 
* ID: juryc
* PROG: Count Order
* LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
int n; cin>>n;
vector<int> p(n),q(n);
for(int& i :p) cin>>i;
for(int& i: q) cin>>i;
vector<int> r(p); 
sort(r.begin(),r.end());
auto eq=[&](vector<int> a,vector<int> b,int n){ int flag=1; for(int i=0;i<n;i++) flag&=(a[i]==b[i]); return flag; };
int cnta=0;
while(true){
if(eq(p,r,n)) break; 
next_permutation(r.begin(),r.end()); 
cnta++;
}
sort(r.begin(),r.end()); 
int cntb=0;
while(true){
if(eq(q,r,n)) break;
next_permutation(r.begin(),r.end()); 
cntb++;
}
cout<<abs(cntb-cnta)<<"\n";
return 0;
}