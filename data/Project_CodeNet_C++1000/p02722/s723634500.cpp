#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
ll N;
cin>>N;
ll ca=0;
ll cb=0;
ll cc=0;
ll N1=N;
ll cd=0;
if(N==2){
cout<<1<<endl;}
else{
for(long long i=1;i*i<=N-1;i++){
if((N-1)%i==0){
ca+=2;}
if(i*i==N-1){
ca--;}}
ca--;
for(long long i=2;i*i<=N;i++){
if(N%i==0){
while(N!=1){
if(N%i==0){
cb++;
N/=i;}
else{
cc++;
goto asd;}}
asd:
if(cc==1){
cb=0;
cc=0;}
else{
goto as;}}
N=N1;}
as:
cc=0;
for(long long i=1;i*i<=cb;i++){
if(cb%i==0){
cc+=2;}
if(i*i==cb){
cc--;}}
if(cc!=0){
cc--;}
N=N1;
for(long long i=2;i*i<=N;i++){
if(N%i==0){
while(N%i==0){
N/=i;}
if((N-1)%i==0&&N!=1){
cd++;}}
N=N1;}
cd++;
cout<<ca+cc+cd<<endl;}}
