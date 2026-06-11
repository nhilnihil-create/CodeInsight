#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int MAX_N = 1000;         // n の最大値
 
int main() {
ll rl=0;
ll lr=0;
ll r=0;
ll l=0;
ll f=0;
ll q=0;
string a;
cin>>a;
char b;
ll n=a.size();
ll aa[n]={};
for(ll i=0; i<n; i++){
if(a.at(i)=='R'){
r++;
}
else{
l++;
}
if(r>0&&l>0){
b=a.at(i);
rl=i;
for(int k=i+1; k<n; k++){
if(b!=a.at(k)){
lr=k;
i=k;
f++;  
break;}
else{
if(b=='R'){
r++;}
else{
l++;}}
}
if(f==0){q++;}
else f=0;
if(r%2==0){
aa[rl-1]+=r/2;
aa[rl]+=r/2;}
else{
aa[rl-1]+=r/2+1;
aa[rl]+=r/2;}
if(l%2==0){
aa[rl-1]+=l/2;
aa[rl]+=l/2;}
else{
aa[rl-1]+=l/2;
aa[rl]+=l/2+1;}
r=1;
l=0;}
if(q==1){
break;
}
}
for(ll i=0; i<n; i++){
cout<<aa[i]<<" ";}}
