#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main(){
  int n,m,q;
  cin >> n >> m >> q;
  int a[55], b[55], c[55], d[55];
  rep(i,q){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--;
    b[i]--;
  }
  vector<int> vec(n+m-1,1);
  rep(i,m-1)vec[i]=0;
  int ans = 0;
  do{
    int zero_cnt=1;
    int score = 0;
    vector<int> A;
    rep(i,n+m-1){
      if(vec[i]==0)zero_cnt++;
      else A.push_back(zero_cnt);
    }
    rep(i,q){
      if(A[b[i]]-A[a[i]]==c[i])score+=d[i];
    }
    ans = max(ans,score);
  }while(next_permutation(vec.begin(),vec.end()));

  cout << ans << endl;
  return 0;
}
