#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin >> a[i];
  }
  
  ll ans=100000000000;
  for(int i=1;i<=100;i++){
    ll s=0;
    for(int j=0;j<N;j++){
      s+=(i-a[j])*(i-a[j]);
      if(j==N-1){
        ans=min(ans,s);
      }
    }
  }
  cout << ans <<endl;
}

    
      