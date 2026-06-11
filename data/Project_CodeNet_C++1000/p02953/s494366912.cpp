#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,b;
  cin >> n;
  if(n==1){
    cout << "Yes" << endl;
    return 0;
  }
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin >> a.at(i);
  for(int i=n-2;i>=0;i--){
    if(a.at(i)>a.at(i+1))
      a.at(i)--;
  }
  bool ans=true;
  for(int i=0;i<n-1;i++)
    if(a.at(i)>a.at(i+1))
      ans=false;
  cout << (ans?"Yes":"No") << endl;
  return 0;
}