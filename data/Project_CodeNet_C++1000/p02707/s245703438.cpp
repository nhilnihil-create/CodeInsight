#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> num(N);
  for(int i=0;i<N-1;i++){
    int A;
    cin >> A;
    num.at(A-1)++;
  }
  for(int i=0;i<N;i++){
    cout << num.at(i) << endl;
  }
}