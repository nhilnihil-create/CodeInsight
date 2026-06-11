#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  vector<long long> a(n);
  cin >> a.at(0);
  
  for(int i=1;i<n;i++){
    long long x;
    cin >> x;
    a.at(i)=x+a.at(i-1);
  }
  
  long long x=a.at(n-1);
  long long ans=x;
  
  for(int i=0;i<n-1;i++){
    ans=min(ans,max(x-2*a.at(i),2*a.at(i)-x));
  }
  
  cout << ans << endl;
}