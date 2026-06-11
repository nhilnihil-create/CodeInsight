#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,k,cnt;
  cin>>n>>k;
  cnt=0;
  while(n!=0){
    n=n/k;
    cnt++;
  }
  cout<<cnt;
}