#include<bits/stdc++.h>
using namespace std;
int N, a[1001000], b[1001000];
string s;

void solve(int x) {
  if( x == 0) return;
  int k = 1;
  while(2*k <= x) k*=2;
  
  for(int i=0; i+k <= x; ++i) {
    b[i] = a[i] ^ a[i+k];
  }
  for(int i=0;i+k<=x;++i) a[i] = b[i];
  solve(x - k);
}

int main() {
  cin>>N>>s;
  int ok = 0;
  for(int i=0;i<N;++i) {
    if(s[i] == '2') ok = 1;
    a[i] = s[i] - '1'; 
  }
  if(ok) {
    for(int i=0;i<N;++i) {
      a[i] %= 2;
    }
  } else {
    for(int i=0;i<N;++i) {
      a[i] /= 2;
    }
  }
  
  solve(N-1);
  
  if(!ok) a[0] *= 2;
  cout<<a[0]<<endl;
  
  return 0;
}
