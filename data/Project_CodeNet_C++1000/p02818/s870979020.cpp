/* 
* ID: juryc
* PROG: Greedy Takahashi
* LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
ll a,b,k; cin>>a>>b>>k;
if(k<=a) cout<<a-k<<"  "<<b<<"\n"; 
else if(k<=a+b) cout<<0<<" "<<b-(k-a)<<"\n"; 
else cout<<0<<" "<<0<<endl;
return 0;
}