#include<bits/stdc++.h>
using namespace std;
int main(){
  long long N;
  cin >> N;
  vector<pair<long long,long long>> A(N);
  for(long long i=0; i<N; i++){
    long long a,b;
    cin >> a >> b;
    A[i].first = a+b;
    A[i].second = a-b;
  }
  sort(A.begin(),A.end());
  long long ans=0,n=-10000000000;
  for(long long i=0;i<N;i++){
    if(A[i].second >= n){
      ans++;
      n = A[i].first;
    }
  }
  cout << ans << endl;
}
