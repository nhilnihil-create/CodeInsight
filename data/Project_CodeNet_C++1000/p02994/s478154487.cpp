#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,l;
  cin>>n>>l;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    a[i]=l+i;
  }
  int s=0;
  for(int i=0;i<n;i++){
    s+=a[i];
  }
  int ans=0;
  for(int i=0;i<n;i++){
    int t=s-a[i];
    if(abs(t-s)<abs(ans-s)) ans=t;
  }
  cout<<ans<<endl;
}