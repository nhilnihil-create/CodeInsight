#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000000;
//------------------------------------------//

int main(){
  int N;cin>>N;
  vector<int> A(N);
  vector<int> B(N);
  rep(i,N){
    cin>>A[i];
    B[i]=A[i];
  }
  sort(B.begin(),B.end());
  reverse(B.begin(),B.end());
  int max=B[0];
  int max_a=B[1];
  
  rep(i,N){
    if(A[i]==max) cout<<max_a<<endl;
    else cout<<max<<endl;
  }
}