#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin>>N>>S;
  int n=S.size();
  
  for(int i=0; i<n; i++){
    int a = S.at(i)+N;
    if(a<='Z') S.at(i) = (char)a;
    else S.at(i) = (char)(a-26);
  }
  cout<<S<<endl;
}