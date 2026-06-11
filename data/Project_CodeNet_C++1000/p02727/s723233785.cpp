#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main() {
ll X,Y,A,B,C;
cin>>X>>Y>>A>>B>>C;
ll a[A]={};
ll b[B]={};
ll c[C]={};
ll counter=0;
for(int i=0;i<A;i++){
cin>>a[i];}
for(int i=0;i<B;i++){
cin>>b[i];}
for(int i=0;i<C;i++){
cin>>c[i];}
sort(a,a+A);
sort(b,b+B);
sort(c,c+C);
ll k=0;
ll w=0;
priority_queue<ll,vector<ll>,greater<ll>>q;
for(int j=0;j<X;j++){
counter+=a[A-1-w];
q.push(a[A-1-w]);
w++;}
w=0;
for(int j=0;j<Y;j++){
counter+=b[B-1-w];
q.push(b[B-1-w]);
w++;}
for(int j=C-1;j>=0;j--){
k=q.top();
if(c[j]>=k){
counter=counter-k+c[j];
q.pop();}
else
break;}
cout<<counter<<endl;}