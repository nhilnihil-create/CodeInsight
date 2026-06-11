#include <bits/stdc++.h>
using namespace std;
using ll=long long;


int main() {
  int n;
  cin >> n;
  
  vector<string> s(n);
  vector<int> t(n);
  
  for(int i=0;i<n;i++){
    cin>>s.at(i);
    cin>>t.at(i);
  }
  string x;
  cin >>x;
  
  int a=0;
  for(int i=0;i<n;i++){
    if(x==s.at(i)){
      a=i+1;
      break;
    }
  }
  
  int c=a;
  
  int sum=0;
  for(int c=a;c<n;c++){
    sum+=t.at(c);
  }
  
  cout << sum <<endl;
}
    
    