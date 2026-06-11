/*
* ID: juryc
* PROG: Welcome to Atcoder
* LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m; cin>>n>>m; 
vector<int> ac(n,0); 
vector<int> wa(n,0); 
int aw,ca; aw=ca=0;
int p; string s;
for(int i=0;i<m;i++){
cin>>p>>s;
--p;
if(s=="AC") ac[p]=1;
else{ if(ac[p]) continue; else wa[p]++; }
}
for(int i=0;i<n;i++)
if(ac[i]) aw+=wa[i],ca++;
cout<<ca<<" "<<aw<<"\n"; 
return 0;
} 
