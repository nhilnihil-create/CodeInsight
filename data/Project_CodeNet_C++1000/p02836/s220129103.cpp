#include <bits/stdc++.h>
using namespace std;
int main () {
  string s;
  cin>>s;
  int N=s.size()/2;
  int counter=0;
  for (int j = 0; j < N; j++) {
  if(s.at(j)!=s.at(s.size()-1-j))
  counter++;}
    cout << counter << endl;
}
