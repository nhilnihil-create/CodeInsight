#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, L;
  cin >> N >> L;
  int S = 0;
  vector<int> vec(N);  
  for(int i = 0; i < N; i++){
    S += (L + i);
    vec.at(i) = L + i;
  }
  
  if(L >= 0){
    sort(vec.begin(),vec.end());
    cout << S - vec.at(0) << endl;
    return 0;
  }
  if(L < 0){
    if(L + N -1 >= 0){
      cout << S << endl;
      return 0;
    }
    if(L + N -1 < 0){
      sort(vec.begin(),vec.end());
      cout << S - vec.at(N-1);
      return 0;
    }
  }
}

  