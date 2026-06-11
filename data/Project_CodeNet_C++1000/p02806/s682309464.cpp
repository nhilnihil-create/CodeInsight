#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,t,sum = 0;
  bool frag = false;
  string s,X;
  vector<int> minute;
  vector<string> name;
  cin >> N;
  for(int i = 0;i<N;i++){
  	cin >> s >> t;
    minute.push_back(t);
    name.push_back(s);
  }
  cin >> X;
  for(int i = 0; i<N;i++){
    if(frag){sum += minute.at(i);}
    if(name.at(i) == X){frag = true;}
  }
  cout << sum << endl;
}