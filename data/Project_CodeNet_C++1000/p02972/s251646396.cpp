#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N,0);
  vector<int> solution(N,0);
  for (int i=0; i<N;i++) {
    cin >> vec[i];
  }

  int counter=0;
  int j=0;
  for (int i=N-1; i>=0; i--) {
    counter=0;
    j=2;
    while (j*(i+1)<=N) {
      counter+=solution[j*(i+1)-1];
      j++;
    }
    counter = counter%2;
    if (counter!=vec[i]) {
      solution[i]=1;
    }
  }
  int balls=0;
  for (int i=0; i<N; i++) {
    balls+=solution[i];
  }
  cout << balls << endl;
  if (balls!=0) {
    for (int i=0; i<N; i++) {
      if (solution[i]==1) {
        cout << i+1 << " ";
      }
    }
  }
}