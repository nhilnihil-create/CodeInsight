#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector <int> hako(N);
  for(int i=0;i<N;i++){
    cin >> hako[i];
  }
  sort(hako.begin(),hako.end());
  int A = hako[N/2-1];
  int B = hako[N/2];
  cout << B-A << endl;
}