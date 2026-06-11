#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,count=0;
  cin >> N;
  vector<int> P(N);
  for(int i=0;i<N;i++){
    cin >> P.at(i);
  }
  for(int i=1;i<N-1;i++){
    if(P.at(i)!=max({P.at(i-1),P.at(i),P.at(i+1)})
       && P.at(i)!=min({P.at(i-1),P.at(i),P.at(i+1)})){
      count++;
    }
  }
  cout << count << endl;
}