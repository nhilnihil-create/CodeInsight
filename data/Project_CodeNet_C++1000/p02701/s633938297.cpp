#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  set<string> s;
  cin>>N;
  string S;
  for(int i = 0;i < N;i++){
    cin>>S;
    s.insert(S);
  }
  cout<<s.size()<<'\n';
}