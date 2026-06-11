#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int>vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  sort(vec.begin(),vec.end());
  for(int i=0; i<N-1; i++){
    if(vec[i] == vec[i+1]){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
      