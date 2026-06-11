/* 
* ID: juryc
* PROG: Semi Common Multiple
* LANG: C++
*/	
#include<bits/stdc++.h>
using namespace std;
#define lcm(a,b) ((a)*(b))/(__gcd(a,b))
typedef long long ll;
int main(){
int n,m; cin>>n>>m;
vector<ll> v(n); 
for(ll& i:v) {cin>>i;}
for(ll& i: v) i/=2;
int t=__builtin_ctz(v[0]);
for(ll& i: v){
if(__builtin_ctz(i)!=t){
cout<<0<<endl; return 0;
}
}
ll lm=1;
for(ll& i: v) lm=lcm(lm,i);
m/=lm;
cout<<(m+1)/2<<"\n";   
return 0;
}