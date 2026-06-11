#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int> 

int main(){
  ll N; cin >> N;
  vector<pair<ll,ll>> A(N);
  rep(i,N) cin >> A[i].second >> A[i].first;

  sort(all(A));

  bool flag = true;
  rep(i,N){
    if (i>0) A[i].second += A[i-1].second;

    if (A[i].first<A[i].second){
      flag = false;
      break;
    }
  }
  
  cout << (flag? "Yes" : "No") << endl;

  return 0;
}
