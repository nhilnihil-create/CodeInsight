#include <bits/stdc++.h>
using namespace std;

int keta(int x){
  int sum=0;
  while(x>0){
    x/=10;
    sum++;
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  
  int ans=0;
  for(int i=1;i<=n;i++){
    if(keta(i)%2==1){
      ans++;
    }
  }
  cout << ans;
  
}
