#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  int N;
  cin>>N;
  vector<int> A(N);
  rep(i,N) cin>>A[i];
  vector<int> a(N);
  copy(all(A),a.begin());
  sort(all(a));
  reverse(all(a));
  rep(i,N){
    if(A[i]==a[0]){
      cout<<a[1]<<endl;;
    }
    else{
      cout<<a[0]<<endl;
    }
  }
}