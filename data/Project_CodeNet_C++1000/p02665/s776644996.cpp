#include <bits/stdc++.h>
using namespace std;
#define nin(n) int n; cin >> n;
#define kin(k) int k; cin >> k;
 
int main() {
  int n; cin>> n;
  vector<long long> a(101010);
  vector<long long> mi(101010);
  vector<long long> max(101010);
  for(int i=0;i<=n;i++){
    cin >> a[i];
  }
  if(n==0){
    if(a[0]==1){
      cout << "1";
    }
    else{
      cout <<"-1";
    }
  }
  else{
  mi[n]=a[n];
  max[n]=a[n];
  for(int i=n-1;i>=0;i--){
    max[i]=max[i+1]+a[i];
    if(mi[i+1]%2==0){
      mi[i]=mi[i+1]/2+a[i];
    }
    else{
      mi[i]=mi[i+1]/2+1+a[i];
    }
  }
  if(mi[0]>1||max[0]<1||a[0]!=0){
    cout << "-1" << endl;
  }
  else{
    long long ans=1;
    long long tmp=1;
    for(int i=1;i<n+1;i++){
      ans=ans+min(2*tmp,max[i]);
      tmp=min(2*tmp,max[i])-a[i];
    }
    cout << ans << endl;
  }
  }
}