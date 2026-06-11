#include <bits/stdc++.h>
using namespace std;
int main(){
  int k,n;	cin >> k >> n;
  vector<int>	A(n);
  for(int i=0;i<n;i++){
    cin >> A.at(i);
  }
  
  int dis=0;
  for(int i=0;i<n-1;i++){
    dis=max(dis,A.at(i+1)-A.at(i));
  }
  dis=max(dis,A.at(0)+k-A.at(n-1));
  cout << k-dis;
}