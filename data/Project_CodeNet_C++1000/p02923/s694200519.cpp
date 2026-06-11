#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int a[100005];
  for(int i=0;i<n;i++)cin>>a[i];
  int ans = 0;
  for(int i=0;i<n;i++){
    int j=i;
    while(j<n-1 && a[j+1]<= a[j])
           j++;
    ans = max(ans,j-i);
    i=j;
  }
    cout<<ans<<"\n";
}
