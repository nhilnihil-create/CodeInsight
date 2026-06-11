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
ll ca=0;
ll d[n]={};
ll f=0;
cin>>ca;
if(ca!=0){
cout << 0 << endl;}
else{
d[0]++;
for(ll i=1; i<n; i++){
cin>>ca;
d[ca]++;}
ca=1;
ll q=0;
if(d[0]!=1) cout << 0 << endl;
else{
for(ll i=0; i<=n-1; i++){
if(d[i]>0){
q=i;}}
for(ll i=1; i<=q; i++){

for(ll k=0; k<d[i]; k++){
ca=ca*d[i-1];
ca%=998244353;}
}
cout << ca << endl;}}}

