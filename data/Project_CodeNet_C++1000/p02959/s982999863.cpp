#include <bits/stdc++.h>
using namespace std;



int main() {
  int N;
  cin>>N;
  vector<long long> mon(N+1);
  for(int i=0;i<=N;i++){
    cin>>mon.at(i);
  }
  vector<long long> yuu(N);
  for(int i=0;i<N;i++){
    cin>>yuu.at(i);
  }
  long long monsum=0;
  for(int i=0;i<=N;i++){
    monsum+=mon.at(i);
  }
  
  reverse(mon.begin(),mon.end());
  reverse(yuu.begin(),yuu.end());
  
  for(int i=0;i<N;i++){
    long long x=mon.at(i);
    mon.at(i)=max(mon.at(i)-yuu.at(i),0ll);
    yuu.at(i)=max(yuu.at(i)-x,0ll);
    mon.at(i+1)=max(mon.at(i+1)-yuu.at(i),0ll);
  }
  long long monsum2=0;
  for(int i=0;i<=N;i++){
    monsum2+=mon.at(i);
  }
  
  cout<<monsum-monsum2<<endl;
}
