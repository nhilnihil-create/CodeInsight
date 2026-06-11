#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  set<int> kk;
  for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
      kk.insert(i*j);
    }
  }
  int N;
  cin >> N;
  if(kk.count(N)){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}