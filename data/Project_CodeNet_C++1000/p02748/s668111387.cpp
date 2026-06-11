#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, M;
  cin >> A >> B >> M;
  vector<int> VA(A);
  vector<int> VB(B);
  vector<vector<int>> VC(M, vector<int>(3));
  for (int i = 0; i < A; i++) cin >> VA.at(i);
  for (int i = 0; i < B; i++) cin >> VB.at(i);
  for (int i = 0; i < M; i++) cin >> VC.at(i).at(0) >> VC.at(i).at(1) >> VC.at(i).at(2);
  int tmp, minA = VA.at(0), minB = VB.at(0);
  for (int i = 1; i < A; i++) minA = min(minA, VA.at(i));
  for (int i = 1; i < B; i++) minB = min(minB, VB.at(i));
  tmp = minA + minB;
  int minC = 10000000;
  for (int i = 0; i < M; i++) minC = min(minC, VA.at(VC.at(i).at(0) - 1) + VB.at(VC.at(i).at(1) - 1)- VC.at(i).at(2));
  cout << min(tmp, minC) << endl;
  return 0;
}