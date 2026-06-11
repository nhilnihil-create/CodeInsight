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
int main(){
ll n,k,r,s,p;
string t;
cin>>n>>k>>r>>s>>p>>t;
ll dp[n][3]={{}};
ll counter=0;
ll ca=0;
for(ll i=0; i<k; i++){
if(t.at(i)=='r'){
dp[i][0]=p;}
else if(t.at(i)=='s'){
dp[i][1]=r;}
else{
dp[i][2]=s;}}
for(ll i=0; i<k; i++){
for(ll m=k; i+m<n; m=m+k){
if(t.at(i+m)=='r'){
dp[i+m][0]=max(dp[i+m-k][1]+p,dp[i+m-k][2]+p);
dp[i+m][1]=max(dp[i+m-k][0],dp[i+m-k][2]);
dp[i+m][2]=max(dp[i+m-k][0],dp[i+m-k][1]);}
else if(t.at(i+m)=='s'){
dp[i+m][1]=max(dp[i+m-k][0]+r,dp[i+m-k][2]+r);
dp[i+m][0]=max(dp[i+m-k][1],dp[i+m-k][2]);
dp[i+m][2]=max(dp[i+m-k][0],dp[i+m-k][1]);}
else{
dp[i+m][0]=max(dp[i+m-k][1],dp[i+m-k][0]);
dp[i+m][1]=max(dp[i+m-k][0],dp[i+m-k][2]);
dp[i+m][2]=max(dp[i+m-k][0]+s,dp[i+m-k][1]+s);}
}}
for(ll i=n-1; i>n-k-1;i--){
ca=max(dp[i][0],dp[i][1]);
ca=max(dp[i][2],ca);
counter+=ca;
ca=0;}
cout<<counter<<endl;}