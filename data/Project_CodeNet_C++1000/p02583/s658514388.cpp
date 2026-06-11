#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,ans;
  ans=0;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
  sort(a.begin(), a.end());
  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      for(int k=0;k<j;k++){
        if(a.at(k)+a.at(j)>a.at(i) && a.at(k)!=a.at(j) && a.at(j)!=a.at(i)){
          ans++;
        }
      }
    }
  }
  cout<<ans;
}