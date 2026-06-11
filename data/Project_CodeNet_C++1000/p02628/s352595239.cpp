#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin >> n >> k;
  vector<int> p(n);
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    p[i]=a;
  }
  sort(p.begin(),p.end());
  int ans=0;
  for(int i=0;i<k;i++){
    ans = ans + p[i];
  }
  cout << ans << endl;
}
