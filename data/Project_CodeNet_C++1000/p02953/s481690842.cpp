#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k=-1;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++)cin >> a[i];
  for(int i=0;i<n;i++){
    if(a[i]+1<k){
      cout << "No" << endl;
      return 0;
    }
    k=max(k,a[i]);
  }
  cout << "Yes" << endl;
  return 0;
}
    