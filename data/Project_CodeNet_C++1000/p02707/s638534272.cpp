#include <bits/stdc++.h>
using namespace std;

int main(){
  int A;
  cin >> A;
  vector<int>B(A+1);
  vector<int>C(A+1);
  for(int i=1;i<=A;i++){
    cin >> B[i];
    C[B[i]]++;
  }
  for(int i=1;i<=A;i++){
    cout << C[i] << endl;
  }
}