using namespace std;
#include <iostream>
#include <algorithm>
#include <string>

int main(){
  int X, N;
  cin >> X >> N;
  vector<int> Ps;
  int p;
  while (cin >> p) Ps.push_back(p);

  vector<int> candidate;
  candidate.push_back(X);

  int count = 1;
  int sub = 1;
  while (count < N + 1){
    candidate.push_back(X - sub);
    candidate.push_back(X + sub);
    count += 2;
    sub += 1;
  }

  for (int i = 0; i < candidate.size(); i ++){
    if (find(Ps.begin(), Ps.end(), candidate[i]) == Ps.end()){
      cout << candidate[i];
      return 0;
    }
  }
}