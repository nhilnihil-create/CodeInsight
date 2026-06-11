#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;cin>>n>>m;
  if(n==0||m==0)cout<<-1<<endl;
  else if(n<10&&m<10)cout<<n*m<<endl;
  else cout<<-1<<endl;
}
