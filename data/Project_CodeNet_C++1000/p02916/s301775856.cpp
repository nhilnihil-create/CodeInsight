#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n),b(n),c(n-1),d(n-1,0);
  int i,s;
  s=0;
  for(i=0;i<n;i++){
    cin >> a.at(i);
    if(i>=1&&a.at(i-1)+1==a.at(i)){
      d.at(a.at(i-1)-1)=1;
    }
  }
  for(i=0;i<n;i++){
    cin >> b.at(i);
    s += b.at(i);
  }
  for(i=0;i<n-1;i++){
    cin >> c.at(i);
    s += c.at(i)*d.at(i);
  }
  cout << s << endl;
}