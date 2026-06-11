#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i;
  cin >> n;
  vector<string> s(n);
  vector<int> t(n);
  for(i=0;i<n;i++){
    cin >> s.at(i) >> t.at(i);
  }
  string x;
  cin >> x;
  
  int j=0,a=0;
  for(i=0;i<n;i++){
    a += t.at(i)*j;
    if(s.at(i)==x){
      j=1;
    }
  }
  
  cout << a << endl;
}