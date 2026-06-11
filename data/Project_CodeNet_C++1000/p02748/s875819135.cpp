#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,M;
  cin>>A>>B>>M;
  vector<int> a(A),b(B);
  int amin=100000,bmin=100000;
  for(int &i:a){
    cin>>i;
    amin=min(amin,i);
  }
  for(int &i:b){
    cin>>i;
    bmin=min(bmin,i);
  }
  int ab=amin+bmin;
  for(int i=0;i<M;i++){
    int x,y,c;
    cin>>x>>y>>c;
    ab=min(ab,a[x-1]+b[y-1]-c);
  }
  cout<<ab<<endl;
}