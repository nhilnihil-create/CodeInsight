#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  vector<int> v2(N);
  int A;
  int maximum=0;
  int sec=0;
  for (int i=0; i<N;i++) {
    cin >> A;
    vec[i]=A;
    v2[i]=A;
  }
  
  sort(v2.begin(),v2.end());
  maximum=v2[N-1];
  sec=v2[N-2];
  if (maximum==sec){
    for (int i=0; i<N;i++) {
    	cout << maximum << endl;
    }
  } else {
    for (int i=0; i<N; i++) {
      if (vec[i]==maximum) {
        cout << sec << endl;
      } else {
        cout << maximum << endl;
      }
    }
  }
  
}