#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N;
  cin>>N;
  vector<long long> a(N);
  for(int i=0;i<N;i++)
    cin>>a.at(i);
  int max=0,index=-1;
  for(int i=0;i<N;i++){
    if(a.at(i)>max){
      max=a.at(i);
      index=i;
    }
  }
  vector<long long> b(N,max);
    sort(a.begin(),a.end());


  if(a.at(N-2)!=a.at(N-1))
    b.at(index)=a.at(N-2);
  for(int i=0;i<N;i++)
    cout<<b.at(i)<<endl;
  
}