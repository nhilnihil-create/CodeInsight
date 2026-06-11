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
ll x,y;
cin>>x>>y;
if(x==1&&y==1){
cout << 1000000 << endl;}
else if(x==1&&y==2){
cout << 500000 << endl;}
else if(x==1&&y==3){
cout << 400000 << endl;}
else if(x==2&&y==1){
cout << 500000 << endl;}
else if(x==2&&y==2){
cout << 400000 << endl;}
else if(x==2&&y==3){
cout << 300000 << endl;}
else if(x==3&&y==1){
cout << 400000 << endl;}
else if(x==3&&y==2){
cout << 300000 << endl;}
else if(x==3&&y==3){
cout << 200000 << endl;}

else if(x==1){
cout << 300000 << endl;}
else if(x==2){
cout << 200000 << endl;}
else if(x==3){
cout << 100000 << endl;}
else if(y==1){
cout << 300000 << endl;}
else if(y==2){
cout << 200000 << endl;}
else if(y==3){
cout << 100000 << endl;}
else {
cout << 0 << endl;}}