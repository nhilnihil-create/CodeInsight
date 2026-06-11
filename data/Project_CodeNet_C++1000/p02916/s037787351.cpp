#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>A(n);
  vector<int>B(n);
  vector<int>C(n-1);
  for(int i=0;i<n;i++)
    cin >> A.at(i);
  for(int i=0;i<n;i++)
    cin >> B.at(i);
  for(int i=0;i<n-1;i++)
    cin >> C.at(i);
  int ans=0,memo=n;
  for(int i=0;i<n;i++){
    ans+=B.at(A.at(i)-1);
    if(memo+1==A.at(i)-1)
      ans+=C.at(memo);
    memo=A.at(i)-1;
  }
  cout << ans << endl;
  return 0;
}