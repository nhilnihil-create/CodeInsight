#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  bool ans = true;
  
  for(int i=0; i<N; i++) cin >> A.at(i);
  for(int i=0; i<N; i++) {
    if(A.at(i)%2==0) {
      if(A.at(i)%3!=0 && A.at(i)%5!=0)
        ans = false;
       }
  }
  if(ans==false) cout <<"DENIED" << endl;
  else cout << "APPROVED" << endl;
}