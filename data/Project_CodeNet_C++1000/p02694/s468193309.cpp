#include<bits/stdc++.h>
using namespace std ;
int main(){
long long n,cnt=0,now=100;
cin >>n ;
while(now<n){
  now+=now/100;
  cnt++;
}
  cout <<cnt<<endl;
}