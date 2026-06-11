#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
typedef std::bitset<6> bit;
 
int main(){
  int N,M,ans=0;
  cin>>N>>M;
  vector<int> H(N),Hmax(N);
  
  for(int i=0;i<N;i++){
    cin>>H.at(i);
    Hmax.at(i)=0;
  }
  int a,b;
  for(int i=0;i<M;i++){
    cin>>a>>b;
    Hmax.at(a-1)=max(Hmax.at(a-1),H.at(b-1));
    Hmax.at(b-1)=max(Hmax.at(b-1),H.at(a-1));
  }
  
  for(int i=0;i<N;i++){
    if(Hmax.at(i)<H.at(i)) ans++;
    //cout<<Hmax.at(i)<<" "<<H.at(i)<<endl;
  }
  
  cout<<ans;
  
  return 0;
}