#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,k;
  cin >> n >>k;
  int64_t a[n]={};
  for(int64_t i=0;i<n;i++)cin >> a[i];
  for(int64_t j=k;j<n;j++){
    if(a[j-k]<a[j])cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
