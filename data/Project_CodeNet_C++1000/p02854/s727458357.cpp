#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long>A(N);
  for(int i=0; i<N; i++)cin >> A.at(i);
  
  long long nagasa, naka1, naka2, ans;
  nagasa = naka1 = naka2 = ans =0;
  
  for(int i=0; i<N; i++){
    nagasa += A.at(i);
  }
  
  for(int i=0; i<N; i++){
    naka1 += A.at(i);
    if(naka1*2>=nagasa)break;
    naka2 += A.at(i);
  }
  
  
  ans += min(2*naka1-nagasa, nagasa-naka2*2);
  
  cout << ans << endl;
}