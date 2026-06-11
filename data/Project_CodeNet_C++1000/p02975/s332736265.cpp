#include <bits/stdc++.h>
using namespace std;
int main(){
long long N; cin>>N;
long long b,c=0;
long long d=0;
long long a1=0;
long long a2=0;
long long a3=0;
long long b1,b2,b3;
long long c1=1;
long long c2=1;
long long c3=1;
long long c4=1;
set<long long> S;
long long a[5]={-1,-1,-1,-1,-1};
for(long long i=0;i<N;i++){
cin>>b;
if(!S.count(b))
{S.insert(b);
 if(b!=0){
 a[d]=b;
 d++;}}
else{
if(b==0){
c4++;}
else if(b==a[0])
c1++;
else if(b==a[1])
c2++;
else if(b==a[2])
c3++;}
if(S.size()==4){
c++;
break;}}
if(c==1){
cout<<"No"<<endl;}
else if(S.count(0)){
if(S.size()==1){
cout<<"Yes"<<endl;}
else if(S.size()==2){
if(c4*2-1==c1||c4*2==c1){
cout<<"Yes"<<endl;}
else{
cout<<"No"<<endl;}}}
else if(S.size()==3){
if(c1==c2&&c2==c3){
while(a[0]>0||a[1]>0){
                   if(a[0]%2!=a[1]%2){
                   a1+=pow(2,a2);
                   } 
                   a[0]/=2; a[1]/=2;
                   a2++;
                   }
a2=0;
while(a1>0||a[2]>0){
                   if(a1%2!=a[2]%2){
                   a3+=pow(2,a2);
                   } 
                   a1/=2; a[2]/=2;
                   a2++;
                   }
if(a3==0)
cout<<"Yes"<<endl;
else
cout<<"No"<<endl;}
else{
cout<<"No"<<endl;}}
else{
cout<<"No"<<endl;}}