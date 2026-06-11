#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  long long N;
  long long Ans=0;
  cin>>N;
  vector<long long> vec(N);
  vector<long long> count(N+1);
  rep(i,N){cin>>vec.at(i);
          count.at(vec.at(i))++;}
  rep(i,N){Ans+=count.at(i+1)*(count.at(i+1)-1)/2;}
  
  rep(i,N){cout<<Ans-count.at(vec.at(i))+1<<endl;}
  
}