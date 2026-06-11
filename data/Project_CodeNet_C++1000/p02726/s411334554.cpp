#include<bits/stdc++.h>
using namespace std;
using ll = long long;

using Edge = pair<int, long long>;
int d[10000];

int main(){
  
  int N, X, Y;
  cin >> N >> X >> Y;

  for(int i=1; i<N; i++){
    for(int j=i+1; j<N+1; j++){
      int dd = min(j-i, abs(i-X)+1+abs(j-Y));
      d[dd]++;
    }
  }
  
  
  for(int i=1; i<N; i++) cout << d[i] << endl;

  return 0;
}