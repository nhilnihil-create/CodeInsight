#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
 int n,a,b;
  cin >> n;
  
 vector<int> d(n);
  rep(i,n) cin >> d.at(i);
  
 sort(d.begin(),d.end());
  
  a=n/2-1;
  b=n/2;
  
  cout << d.at(b)-d.at(a) << endl;
  
}
  
  
  
