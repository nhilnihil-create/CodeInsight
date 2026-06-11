#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  int N;
  cin >> N;
  set<int> S;
  rep(i,N){
    int x = 0;
    cin >> x;
    S.insert(x);
  }
  if(N == S.size()){
    cout << "YES";
  }
  else{
    cout << "NO";
  }
}