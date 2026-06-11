#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, ans=0, tmp;
  cin >> n;
  int a[n], c[n-1];
  for(int i=0;i<n;i++){
    cin >> a[i];
    a[i]--;
  }
  for(int i=0;i<n;i++){
    cin >> tmp;
    ans += tmp;
  }
  for(int i=0;i<n-1;i++){
    cin >> c[i];
  }
  for(int i=0;i<n-1;i++){
    if((a[i]+1)==a[i+1])
      ans += c[a[i]];
  }
  cout << ans << endl;
}