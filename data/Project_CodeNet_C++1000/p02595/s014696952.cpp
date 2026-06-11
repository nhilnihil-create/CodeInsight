#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long long D;
  cin >> N >> D;
  
  long long list[N][2];
  for(int i=0; i<N; i++)
    cin >> list[i][0] >> list[i][1];
  
  int res = 0;
  long long dis = 0;
  
  for(int i=0; i<N; i++){
    dis = list[i][0]*list[i][0] + list[i][1]*list[i][1];
    
    if(dis <= D*D)
      res++;
  }
  cout << res << endl;
}