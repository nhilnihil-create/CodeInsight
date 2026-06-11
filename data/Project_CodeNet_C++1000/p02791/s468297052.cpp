#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>P(N);
  for(int i=0; i<N; i++)cin >> P.at(i);
  
  int mini =P.at(0);
  int count =0;
  
  for(int i=0; i<N; i++){
    if(P.at(i)<=mini){
      mini=P.at(i);
      count ++;
    }
  }
  
  cout << count << endl;
  
}