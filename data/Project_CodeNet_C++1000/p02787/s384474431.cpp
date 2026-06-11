#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,H;
  cin>>H>>N;
  vector<int> p(H+1,167167167);
  p[0]=0;
  for(int j=0;j<N;j++){
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=H;i++){
      p[i]=min(p[i],p[max(i-a,0)]+b);
    }
  }
  cout<<p[H]<<endl;
}