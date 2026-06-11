#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n,d; cin>>n>>d;
  int cnt=0;
  vector<vector<int>> x(n,vector<int>(d));
  for(int i=0;i<n;i++) for(int j=0;j<d;j++) cin>>x[i][j];
  for(int i=0;i<n;i++) {
    for(int j=i;j<n;j++) {
      int sum=0;
      for(int k=0;k<d;k++) {
        sum+=(x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
      }
      for(int l=1;l*l<=sum;l++) {
        if(l*l==sum) cnt++;
      }
    }
  }
  cout<<cnt<<endl;
}
