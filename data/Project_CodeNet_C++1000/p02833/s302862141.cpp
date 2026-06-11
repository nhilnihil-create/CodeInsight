/*
* ID: juryc
* PROG: Double Factorial
* LANG: C++
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
int64_t n; cin>>n;
if(n%2) cout<<0<<"\n";
else{
n/=2; 
int64_t g=5;
int64_t cnt=0;
while(n/g){
cnt=(cnt+n/g);
g*=5; 
}
cout<<cnt<<"\n"; 
}
return 0;
}