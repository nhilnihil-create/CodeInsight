#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,m,ans=(1<<18),sum=0;
  cin >> n;
  int64_t a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum+=a[i];
  }
  ans=sum;
  for(int i=0;i<n;i++){
    m+=a[i];
    ans=min(ans,abs(m*2-sum));
  }
  cout << ans << endl;
}
