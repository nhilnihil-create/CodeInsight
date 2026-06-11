#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  
  int n=0, m=0;
  
  for (int i=1 ; i<N ; i++)
    n += i;
  for (int i=1 ; i<M ; i++)
    m += i;
  
  cout << n+m << endl;
}