#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
typedef std::bitset<6> bit;
 
int main(){
  int N,K,d,A;
  cin>>N>>K;
  int ans=N;
  map<int,string> Abuf;
  for(int i=0;i<K;i++){
    cin>>d;
    for(int j=0;j<d;j++){
      cin>>A;
      if(!Abuf.count(A)){
        ans--;
        Abuf[A]="okashi";
      } 
      
    }
  }
    cout<<ans;
  return 0;
}