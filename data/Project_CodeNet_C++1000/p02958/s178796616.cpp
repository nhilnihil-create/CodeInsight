#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N;
  cin >> N;
  vector<int> P(N);
  for(int i = 0; i < N; i++){
    cin >> P.at(i);
  }
  vector<int> Q = P;
  vector<int> R = P;
  sort(P.begin(), P.end());
  if(P == Q){
    cout << "YES" << endl;
    return 0;
  }
  for(int i = 0; i < N - 1; i++){
    for(int j = i + 1; j < N; j++){
      swap(Q.at(i), Q.at(j));
      if(P == Q){
        cout << "YES" << endl;
        return 0;
      }
      swap(Q.at(i), Q.at(j));
    }
  }
  cout << "NO" << endl;
}