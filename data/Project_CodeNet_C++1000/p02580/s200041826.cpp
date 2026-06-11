#include<bits/stdc++.h>
using namespace std;
int main(){
  long H,W,M;cin>>H>>W>>M;
  vector<long>X(W),Y(H);
  vector<pair<long,long>>s;
  
  for(long i=0;i<M;i++){
    long h,w;cin>>h>>w;
    Y[h-1]++;X[w-1]++;
    s.push_back(pair<long,long>(h-1,w-1));
  }
  long x=0;for(long t:X)x=max(x,t);
  long y=0;for(long t:Y)y=max(y,t);
  set<long>IX,IY;
  for(long i=0;i<W;i++)if(x==X[i])IX.insert(i);
  for(long i=0;i<H;i++)if(y==Y[i])IY.insert(i);
  
  long c=0;
  for(long i=0;i<M;i++){
    if(IY.find(s[i].first)!=IY.end()
       &&IX.find(s[i].second)!=IX.end())
      c++;
    
  }
  cout<<(c<IX.size()*IY.size()?x+y:x+y-1);
}