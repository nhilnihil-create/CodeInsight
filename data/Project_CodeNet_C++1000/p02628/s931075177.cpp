#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<int> arr(n);
  priority_queue<int> pq;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    pq.push(-arr[i]);
  }
  int ans=0;
  while(k-- && !pq.empty()){
      ans-=pq.top();
      pq.pop();
  }
  cout<<ans<<endl;
}
 