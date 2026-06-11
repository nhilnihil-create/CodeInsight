#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  vector<pair<long long,long long>>P(N);

  for (int i = 0; i < N; i++) { 
    cin >> P.at(i).second >> P.at(i).first;
  }
  sort(P.begin(), P.end());
  
  long long time = 0;
  for (int i = 0; i < N; i++) { 
    if (time + P.at(i).second > P.at(i).first){
      cout << "No" << endl;
      return 0;
    }
    time += P.at(i).second;
  }
  cout << "Yes" << endl;
}
  
      
    