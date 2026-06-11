#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,ans=0,S=0,sum=0;
  cin >> n;
  int64_t a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum+=a[i];
  }
  sort(a,a+n);
  int k=n/2;
  if(n%2==0)k--;
  for(int i=0;i<n;i++){
    S+=a[i];
    if(i>k){
      ans=a[i]-a[i-1];
      break;
    }
  }
  cout << ans << endl;
}