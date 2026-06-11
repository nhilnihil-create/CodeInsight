#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int MAX_N = 1000;         // n の最大値
 
// nCk を取得
double nCk(int n, int k) {
double res=1.0;
for(int i=0; i<n; i++){
res*=0.5;}
for(int i=0; i<k; i++){
res*=(double)(n-i);
res/=(double)(k-i);
}
return res;}
 
int main() {
ll n;
cin>>n;
ll a[n]={};
for(ll i=0; i<n; i++){
cin>>a[i];}
ll rui[n]={};
rui[0]=a[0];
for(ll i=1; i<n; i++){
rui[i]=rui[i-1]+a[i];}
ll ma=rui[n-1];
ll ca=0;
ll ans =1000000000000;
for(ll i=0; i<n; i++){
if(ma - rui[i] >= rui[i]){
ca = ma -rui[i] -rui[i];}
else {
ca = ( rui[i] - (ma - rui[i]));}
ans = min(ca , ans);}
cout <<ans<< endl;
return 0;}

