#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  string Ans="YES";
  cin>>N;
  vector<int> vec(N);
  rep(i,N){cin >> vec.at(i);}
  sort(vec.begin(),vec.end());
  rep(i,N-1){if(vec.at(i+1)==vec.at(i)){Ans="NO";break;}}
  cout<<Ans<<endl;
}