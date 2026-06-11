#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int a;
  set<int>S;
  for(int i = 0; i<N; i++){
    cin >> a;
    if(S.count(a)){
      cout << "NO" << endl;
      return 0;
    }
    S.insert(a);
  }
  cout << "YES" << endl;
  return 0;
  
}