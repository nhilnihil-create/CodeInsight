#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  if(n==1){
    cout<<0<<endl;
    return 0;
  }
  string s;
  cin>>s;
  int a=0;
  for(int i=0;i<n-1;i++){
    if(s[i]!=s[i+1]){
      a++;
    }
  }
  a=max(0,a-2*k);
  cout<<n-a-1<<endl;
}