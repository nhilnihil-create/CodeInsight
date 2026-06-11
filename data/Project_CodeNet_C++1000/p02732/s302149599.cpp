#include <bits/stdc++.h>
using namespace std;
int64_t choose(int64_t n) {
  return n*(n-1)/2;
}

int main() {
  int N;
  cin>>N;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  vector<int> kaz(N+1);
  
  for(int i=0;i<N;i++){
    
    kaz.at(vec.at(i))++;
  }
  int64_t sum=0;
  for(int i=1;i<=N;i++){
    sum+=choose(kaz.at(i));
  }
  for(int i=0;i<N;i++){
    int64_t ans=sum-choose(kaz.at(vec.at(i)))+choose(kaz.at(vec.at(i))-1);
    cout<<ans<<endl;
  }
}
