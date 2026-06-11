#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,Ans=1;
  cin>>N;
  
  vector<string> vec(N);
  rep(i,N){cin >> vec.at(i);}
  sort(vec.begin(), vec.end());
  
  rep(i,N-1){if(vec.at(i+1)!=vec.at(i)){Ans++;}}
  cout<<Ans<<endl;
}
