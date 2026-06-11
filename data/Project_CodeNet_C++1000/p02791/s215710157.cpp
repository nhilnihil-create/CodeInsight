/* 
* ID: juryc
* PROG: Low Elements
* LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
int n; cin>>n; 
vector<int> v(n); 
for(int& i: v) cin>>i;
int mi=0x3f3f3f3f,cnt=0;
for(int i: v){
mi=min(mi,i); if(mi==i) cnt++; 
}
cout<<cnt<<"\n"; 
return 0;
}