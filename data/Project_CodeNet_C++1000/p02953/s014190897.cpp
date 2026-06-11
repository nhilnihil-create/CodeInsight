#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<long long>a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    a[i]--;
  }
  for(int i=0;i<n-1;i++){
    if(a[i]> a[i+1]){
      a[i+1]++;
      if(a[i]>a[i+1]){
        cout<<"No"<<endl;
        return 0;
      }
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}