#include <bits/stdc++.h>
using namespace std;

int main() {
  int cnt=0;
  int n; cin>>n;
  for(int i=1;i<=n;i++) {
    if(to_string(i).size()%2==1)cnt++;
  }
  cout<<cnt<<endl;
}
