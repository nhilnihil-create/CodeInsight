#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N;
  int result = 1;
  long long time = 0;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  vector<pair<int, int> > C(N);
  
  for(int a = 0;a < N;a++){
    cin >> A[a];
    cin >> B[a];
    C[a] = make_pair(B[a], A[a]);
  }
  sort(C.begin(), C.end());
  for(int a = 0;a < N;a++){
    if(time + C[a].second > C[a].first){
     result = 0; 
      break;
    }
    time += C[a].second;
    
  }
  
  if(result == 0){
   cout << "No" << endl; 
  }else{
   cout << "Yes" << endl; 
  }
  
}