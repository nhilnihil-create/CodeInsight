#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  int n,i;
  ll a[200005],s=0,ls;
  
  cin >> n;
  for (i=0;i<n;i++){
    cin >> a[i];
    s+=a[i];
  }
  
  i=1;
  ls=a[0];
  while (i<n && ls*2<s){
    ls+=a[i];
    i++;
  }
  
  ll v1,v2;
  v1=ls*2-s;
  ls-=a[i-1];
  v2=s-ls*2;
  
  cout << min(v1,v2) << endl;
  
  return 0;
}