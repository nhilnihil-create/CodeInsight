#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int A,B,M;
  cin>>A>>B>>M;
  int amin=1000000;
  int bmin=1000000;
  int a[A];
  int b[B];
  int x,y,c;
  int answer=0;
  for (int i=0;i<A;i++){
      cin>>a[i];
      amin=min(amin,a[i]);

  }
  for (int i=0;i<B;i++){
      cin>>b[i];
      bmin=min(bmin,b[i]);

  }
  answer=amin+bmin;
  for (int i=0;i<M;i++){
      cin>>x>>y>>c;
      answer=min(answer,(a[x-1]+b[y-1]-c));
  }
  cout<<answer<<endl;}