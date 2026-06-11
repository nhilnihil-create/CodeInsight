#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >>N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin >> a[i];
  }
  
  int ans=0;
  for(int i=0;i<N-1;i++){
    for(int j=i+1;j<N;j++){
      ans+=a[i]*a[j];
    }
  }
  
  cout << ans <<endl;
}
