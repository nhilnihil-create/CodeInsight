#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)	for(long long i=0;i<n;i++)

int main(){
  long long n;	cin >> n;
  if(n%2==1){
    cout << 0;
    return 0;
  }
  
  long long ans=0;
  long long w=10;
  while(w<=n){
    ans+=n/w;
    w*=5;
  }
  cout << ans;
}