#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  pair<string,int> playlist[50];
  for(int i=0; i<N; i++){
    string s; int t; cin >> s >> t;
    playlist[i]=make_pair(s,t);
  }
  
  string X; cin >> X;
  
  int sum=0;
  bool slp=false;
  
  for(int i=0; i<N; i++){
    if(slp) sum+=playlist[i].second;
    if(playlist[i].first==X) slp=true;
  }
  
  cout << sum << endl;
}