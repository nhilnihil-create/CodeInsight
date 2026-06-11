#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  int n;
  cin >> n;
  vector<ll>a(n);
  for(int i=0;i<n;++i) cin >> a[i];
  int pre=-999;
  for(int i=0;i<n;i++){
    if(pre<=a[i]-1){
      pre=a[i]-1;
    }else if(pre<=a[i]){
      pre=a[i];
    }else {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}