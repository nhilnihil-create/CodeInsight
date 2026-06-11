#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int cnt=0;
  for(int i=1;i<=n;i++){
     string s=to_string(i);
    if((s.size())%2==0)continue;
    cnt++;
  }
  cout<<cnt<<endl;
}