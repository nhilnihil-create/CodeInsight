#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(){
  int n;
  cin>>n;
  vector<int> a(n-1);
  for(int i=0;i<n-1;i++){
    cin>>a[i];
  }
  vector<int> x(n+1);
  for(int i=0;i<n;i++){
    x[a[i]]++;
  }
  for(int i=1;i<=n;i++){
    cout<<x[i]<<endl;
  }
}