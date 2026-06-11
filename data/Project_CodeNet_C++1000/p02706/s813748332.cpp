#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  int a[n];
  int64_t sum=0;
  for(int i=0;i<m;i++){
    cin >> a[i];
    sum+=a[i];
  }
  if(n-sum<0)cout << -1 << endl;
  else cout << n-sum << endl;
}
