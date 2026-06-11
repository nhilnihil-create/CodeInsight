#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,a;
  cin>>N;
  map<int, int> s;
  for(int i=1; i<N+1; i++){
    cin>>a;
    s[a] = i;
  }
  for(int i=1; i<N+1; i++){
    if(i==1) cout<<s[i];
    else cout<<" "<<s[i];
  }
  cout<<endl;
}