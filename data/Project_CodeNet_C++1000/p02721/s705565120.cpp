#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
ll N,K,C;
cin>>N>>K>>C;
string s;
cin>>s;
ll a[N]={};
ll b[N]={};
ll counter=0;
for(ll i=0;i<N;i++){
if(s.at(i)=='o'){
counter++;
a[i]+=counter;
if(K==counter){
break;}
i=i+C;
}}
counter=0;
for(ll i=0;i<N;i++){
if(s.at(N-1-i)=='o'){
counter++;
b[N-1-i]=K+1-counter;
if(K==counter){
break;}
i=i+C;
}}
for(ll i=0;i<N;i++){
if(a[i]==b[i]&&a[i]!=0){
cout<<i+1<<endl;}}}
