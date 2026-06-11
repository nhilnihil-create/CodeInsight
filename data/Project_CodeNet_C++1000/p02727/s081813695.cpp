#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int X,Y,A,B,C;
  cin>>X>>Y>>A>>B>>C;
  vector<pair<int,int>> D(A+B+C);
  for(int i=0;i<A;i++){
    int p;
    cin>>p;
    D[i]=make_pair(p,0);
  }
  for(int i=0;i<B;i++){
    int q;
    cin>>q;
    D[A+i]=make_pair(q,1);
  }
  for(int i=0;i<C;i++){
    int r;
    cin>>r;
    D[A+B+i]=make_pair(r,2);
  }
  sort(D.begin(),D.end());
  reverse(D.begin(),D.end());
  int c=0,r=0,g=0,j=0;
  for(pair<int,int> p:D){
    if(p.second==2){
      c++;
      j+=p.first;
    }else if(p.second==0){
      if(r<X){
        r++;
        j+=p.first;
      }
    }else if(g<Y){
      g++;
      j+=p.first;
    }
    if(c+r+g==X+Y){
      cout<<j<<endl;
      return 0;
    }
  }
}