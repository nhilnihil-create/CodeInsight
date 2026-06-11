#include <bits/stdc++.h>
using namespace std;

int main() {
  int k,a;
  cin>>k;
  a=0;
for(int i=1;i<k+1;i++){
for(int j=1;j<k+1;j++){
for(int l=1;l<k+1;l++){
a+=gcd(gcd(i,j),l);
}}}  
  cout<<a<<endl;
}
