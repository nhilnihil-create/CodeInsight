#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>A(N),copy(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
    copy[i] = A[i];
  }
  int iti,ni;
  sort(copy.begin(),copy.end());
  iti = copy[N-1];
  ni=copy[N-2];
  for(int i=0; i<N; i++){
    if(A[i] == iti){
      cout << ni << endl;
    }
    else{
      cout << iti << endl;
    }
  }
}
