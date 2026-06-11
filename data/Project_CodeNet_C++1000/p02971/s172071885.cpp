#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  
  vector<int> a(N),b(N);
  for(int i=0; i<N; i++){
    cin>>a.at(i);
    b.at(i) = a.at(i);
  }
  sort(a.begin(), a.end());
  int x, y;
  x = a.at(N-1);
  y = a.at(N-2);
  
  for(int i=0; i<N; i++){
    if(b.at(i) == x) cout<<y<<endl;
    else cout<<x<<endl;
  }
}