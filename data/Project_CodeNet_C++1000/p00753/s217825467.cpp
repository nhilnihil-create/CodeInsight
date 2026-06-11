#include<bits/stdc++.h>
using namespace std;
const int MAX = 123456*2;
int p[MAX];
int N;
int main(){
  for(int i=2;i*i<MAX;i++){
    if( p[i] ) continue;
    for(int j=i+i;j<MAX;j+=i)
      p[j] = 1;    
  }
  while( cin >> N && N ){
    int cnt = 0;
    if( N == 1 ) {
      cout << 1 << endl; continue;
    }
    for(int i=N+1;i<2*N;i++) cnt+=(1-p[i]);
    cout << cnt << endl;
  }  
}