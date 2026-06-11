#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W,N; cin>>H>>W>>N;
  if(H<W){ swap(H,W); }
  int r = (N+H-1)/H;
  cout << r <<"\n";
}