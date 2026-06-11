#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i,n){
    cin >> A[i];
  }
  rep(i,n){
    if(A[i]%2==0){
      if(A[i]%3==0||A[i]%5==0)continue;
      else{
        cout << "DENIED" << endl;
        return 0;
      }
    }
  }
  cout << "APPROVED"<<endl;
  return 0;
}
