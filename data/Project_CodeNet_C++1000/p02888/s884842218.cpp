#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,cnt=0;
  cin >> n;
  int L[n];
  for(int i=0;i<n;i++)cin >> L[i];
  sort(L,L+n);
  for(int i=0;i<n-2;i++){
    for(int j=i+1;j<n-1;j++){
      for(int k=j+1;k<n;k++){
        if(L[j]<L[i]+L[k] && L[k]<L[i]+L[j])cnt++;
      }
    }
  }
  cout << cnt << endl;
}