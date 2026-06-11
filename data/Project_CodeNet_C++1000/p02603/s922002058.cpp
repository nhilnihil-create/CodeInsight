#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,sum=1000;
  cin >> n;
  int64_t a[n];
  for(int i=0;i<n;i++)cin >> a[i];
  for(int i=0;i<n-1;i++){
    int64_t cnt=0;
    if(a[i]<a[i+1])cnt=sum/a[i];
    sum+=(a[i+1]-a[i])*cnt;
  }
  cout << sum << endl;
}
