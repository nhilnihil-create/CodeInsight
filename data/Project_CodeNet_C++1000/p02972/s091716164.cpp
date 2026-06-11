#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int>a(n+1);
  vector<bool>ball(n+1);
  for(int i=1;i<=n;i++) cin>>a[i];
  int m=0;
  vector<int>b;
  for(int i=n;i>=1;i--){
    int j=2;
    int now=0;
    while(i*j<=n){
      if(ball[i*j]) now++;
      j++;
    }
    if(now%2!=a[i]){
      m++;
      b.push_back(i);
      ball[i]=true;
    }
  }
  cout<<m<<endl;
  for(int i=0;i<m;i++) cout<<b[i]<<" ";
}
