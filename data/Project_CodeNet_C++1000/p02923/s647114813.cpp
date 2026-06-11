#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;cin>>N;
  vector<int> H(N);
  for(int i=0;i<N;i++) cin>>H.at(i);
  priority_queue<int> A;
  int count=0;
  for(int i=0;i<N-1;i++){
    if(H.at(i)>=H.at(i+1)) count++;
    else{
      A.push(count);
      count=0;
    }
  }
  A.push(count);
  int ans=A.top();
  cout<<ans<<endl;
}

