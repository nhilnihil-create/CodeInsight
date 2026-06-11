#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin>>N;
  vector<int>vec(N);
  vector<int>ans(N);
  for(int i=0;i<N;i++){
    cin >> vec[i];
    ans[vec[i]-1]=i+1;
  }
  for(int i=0;i<N;i++){
    if(i == N-1){
      cout << ans[i] << endl;
    }
    else{
      cout<<ans[i]<<" ";
    }
  }
}
