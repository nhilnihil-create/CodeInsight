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
ll l,r;
cin>>l>>r;
ll a=2020;
if(r-l>2020){
cout<<0<<endl;}
else{
for(ll i=l; i<=r; i++){
for(ll k=i+1; k<=r; k++){
a=min((i%2019)*(k%2019)%2019,a);}}
cout<<a<<endl;}}
