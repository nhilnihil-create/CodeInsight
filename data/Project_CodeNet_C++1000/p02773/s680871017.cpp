/*
* ID: juryc
* PROG: poll
* LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
int n; string s; cin>>n;
map<string,int> mp;
int mx=0;
while(n--){
cin>>s;
if(mp.find(s)==mp.end()) mp[s]=1;
else mp[s]++;
mx=max(mx,mp[s]); 
}
for(auto i: mp){
if(i.second==mx) cout<<i.first<<endl; 
}
}