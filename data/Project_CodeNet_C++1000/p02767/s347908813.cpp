#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,ans=(1<<25);
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  sort(a,a+n);

  for(int i=a[0];i<=a[n-1];i++){
    int sum=0;
    for(int j=0;j<n;j++){
      int s=abs(a[j]-i);
      sum+=s*s;
    }
    ans=min(ans,sum);
  }
  cout << ans << endl;
}
