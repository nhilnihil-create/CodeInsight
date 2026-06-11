#include <bits/stdc++.h>
using namespace std;
int main() {
long long N;
cin>>N;
long long a;
a=N;
long long x;
long long y;
x=N/1000000000+1;
y=N%1000000000;
y=1000000000-y;
if(x==1000000001){
cout<<0<<" "<<0<<" "<<1000000000<<" "<<0<<" "<<0<<" "<<1000000000<<endl;}
else
cout<<0<<" "<<0<<" "<<1000000000<<" "<<y<<" "<<1<<" "<<x<<endl;}
