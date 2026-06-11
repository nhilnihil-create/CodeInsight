/* 
* ID: juryc
* PROG: Brick Break
* LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
int n;cin>>n;
vector<int> v(n); 
for(int& i: v) cin>>i;
//sort(v.begin(),v.end()); 
int re=1;
for(int i:v){
if(i==re)re++;
}
if(re==1) cout<<-1<<endl;
else{cout<<n-re+1<<endl; }
return 0;
}