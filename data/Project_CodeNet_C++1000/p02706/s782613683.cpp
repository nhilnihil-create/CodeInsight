#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,sum=0;
  cin >> N >> M;
  for(int i=0; i<M;i++){
    int a;
    cin >> a;
    sum += a;
  }
  if(sum >N){
    cout << -1 << endl;
  }
  else{
    cout << N-sum << endl;
  }
}
