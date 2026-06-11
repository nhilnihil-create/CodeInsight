#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>H(N);
  for(int i=0; i<N; i++)cin >> H.at(i);
  
  string ans ="Yes";
  for(int i=N-1; i>0; i--){
    if(H.at(i)-H.at(i-1)<-1){
      ans = "No";
      break;
    }
    else if(H.at(i)-H.at(i-1)==-1)H.at(i-1)--;
  }
  
  cout << ans << endl;
}