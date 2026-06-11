#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  int n = N;
  N = pow(2,N);
  vector<int> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  sort(vec.rbegin(),vec.rend());
  
  bool flag = true;
  
  vector<int> done(0);
  done.push_back(vec[0]);
  
  multiset<int> MS;
  for(int i=1; i<N; i++){
    MS.insert(vec[i]);
  }
  
  for(int i=0; i<n; i++){
    int D = done.size();
    for(int j=0; j<D; j++){
      auto B = MS.begin();
      auto itr = MS.lower_bound(done[j]);
      if(itr == B){
        flag = false;
        continue;
      }
      itr--;
      int x = *itr;
      done.push_back(x);
      MS.erase(itr);
    }
  }
  
  if(flag){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  
}