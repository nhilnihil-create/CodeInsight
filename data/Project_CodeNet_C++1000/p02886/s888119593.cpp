#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n];
 int64_t sum=0;
  for(int i=0;i<n;i++)cin >> a[i];
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      sum+=a[i]*a[j];
    }
  }
  cout << sum << endl;
}