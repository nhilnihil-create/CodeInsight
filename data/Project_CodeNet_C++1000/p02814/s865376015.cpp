#include <bits/stdc++.h>
using namespace std;
int main(){
long long H,W,c=0; cin>>H>>W;
long long counter=0;
long long a[H]={0};
long long aco=0;
long long bco=0;
cin>>a[0];
long long cco=a[0];
counter=a[0];
long long counter1=counter;
long long counter2;
long long answer=0;
long long ddo=0;
for(long long i=1;i<H;i++){
cin>>a[i];}
while(cco%2==0){
aco++;
cco/=2;}
for(long long i=1;i<H;i++){
cin>>a[i];
ddo=a[i];
while(ddo%2==0){
bco++;
ddo/=2;}
if(aco!=bco){
c=1;
goto asd;}
bco=0;}
for(long long j=0;j<H;j++){
counter=a[j];
counter2=__gcd(counter1,counter);
answer=counter*counter1/counter2;
counter1=answer;}
asd:
if(c==1) 
cout<<0<<endl;
else
cout<<(W+answer/2)/answer<<endl;
}
