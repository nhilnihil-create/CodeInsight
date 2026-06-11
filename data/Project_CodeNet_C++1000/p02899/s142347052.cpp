#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
int main() {
  int n;
  cin>>n;
  vector<vector<int>> a(n,vector<int>(2));
  rep(i,n){
    cin>>a[i][0];
    a[i][1]=i+1;
  }
  sort(a.begin(),a.end());
  rep(i,n){
    cout<<a[i][1]<<" ";
  }
}