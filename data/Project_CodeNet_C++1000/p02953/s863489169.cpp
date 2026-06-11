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
ll a[n+10]={};
ll f=0;
ll q=0;
ll w=0;
for(ll i=0; i<n; i++){
cin>>a[i];}
for(ll i=0; i<n; i++){
if(q==2){
cout<<"No"<<endl;
f=1;
break;}
else if(a[i]-a[i+1]>=2&&a[i+1]!=0){
cout<<"No"<<endl;
f=1;
break;}
else if(a[i]==1+a[i+1]){
q++;}
else if(a[i]<a[i+1])
q=0;}
if(f!=1){
cout<<"Yes"<<endl;}}
