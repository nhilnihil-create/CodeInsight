#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
  int N;
  cin>>N;
  vector<int>A(N);
  vector<int>B(N);
  vector<int>C(N-1);
  int ans=0;
  rep(i,N){
      cin>>A[i];
  }
  rep(i,N){
    cin>>B[i];
    ans+=B[i];
  }
  rep(i,N-1){
      cin>>C[i];
  }
  rep(i,N){
    if(i!=0){
        if(A[i]-A[i-1]==1){
            ans+=C[A[i]-2];
        }
    }
  }
  cout<<ans<<endl;
}
