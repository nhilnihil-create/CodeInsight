#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>tako(n);
  for(int i=0;i<n;i++)
    cin >> tako.at(i);
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i!=j)
        ans+=tako.at(i)*tako.at(j);
    }
  }
  cout << ans/2 << endl;
  return 0;
}