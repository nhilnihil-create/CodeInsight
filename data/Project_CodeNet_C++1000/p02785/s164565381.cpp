#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,k,sum=0;
  cin >> n >> k;
  int a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  sort(a,a+n,greater());
  for(int i=k;i<n;i++){
    sum+=a[i];
  }
  cout << sum << endl;
}