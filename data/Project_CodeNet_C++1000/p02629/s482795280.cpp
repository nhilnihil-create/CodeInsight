#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  list <char> s; 
  cin>>n;
  while(n){
    n--;
    s.push_front('a'+n%26);
    n/=26;
  }
  string ss(s.begin(), s.end());
  cout<<ss<<endl;
  return 0;
}