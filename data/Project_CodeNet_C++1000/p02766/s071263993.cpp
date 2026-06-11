#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >>n>>k;
  if(n==0){
    cout <<1<<endl;
    return 0;
  }
  int ans=0;
  while(n!=0){
    n/=k;
    ans++;
  }
  cout <<ans<<endl;
}