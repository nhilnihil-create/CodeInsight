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
ll h,w;
cin>>h>>w;
ll ans=0;
if(h==1){
cout << 1 << endl;}
else if(w==1){
cout << 1 << endl;}
else
if(h%2==0){
ans=(h/2)*w;
cout << ans << endl;}
else if(w%2==0){
ans = (w/2)*h;
cout << ans << endl;}
else{
ans = (w*h+1)/2;
cout<< ans <<endl;}}
