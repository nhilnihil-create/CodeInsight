#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N;
  cin>>N;
  vector<long long> p(N);
  for(int i=0;i<N;i++)
    cin>>p.at(i);
  long long min=p.at(0)+1,count=0;
  for(int i=0;i<N;i++){
    if(p.at(i)<min){
      min=p.at(i);
      count++;
    }
  }
  cout<<count<<endl;
}