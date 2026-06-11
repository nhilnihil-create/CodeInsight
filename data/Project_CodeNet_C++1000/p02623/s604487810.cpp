#include<bits/stdc++.h>
using namespace std;
int main(){
  long n,m,k,temp;
  cin >> n >> m >> k;
  vector<long> a(n+1,0),b(m+1,0);
  for(int i=1;i<=n;i++){
    cin >> temp;
    a.at(i) = a.at(i-1) + temp;
  }
  for(int i=1;i<=m;i++){
    cin >> temp;
    b.at(i) = b.at(i-1) + temp;
  }
  int b_idx=m,ans=0;
  for(int i=0;i<=n;i++){
    if(a.at(i)>k)break;
    while(a.at(i) + b.at(b_idx) > k)b_idx--;
    ans=max(ans,i+b_idx);
  }
  cout << ans << endl;
  return 0;
}