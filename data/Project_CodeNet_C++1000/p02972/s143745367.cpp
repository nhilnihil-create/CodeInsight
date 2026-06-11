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
  int N; cin >> N;
  bool a[N+1]; rep(i,N) cin >> a[i+1];

  bool c[N+1];
  for (int i=N;i>=1;i--){
    bool tot = 0;
    for (int j=2;j*i<=N;j++) tot ^= c[j*i];
    c[i] = a[i]^tot;
  }

  int M = 0;
  vector<int> ans;
  for (int i=1;i<=N;i++){
    if (c[i]) {
      ans.push_back(i);
      M++;
    }
  }
  if (M==0){
    cout << 0 << endl;
    return 0;
  }

  cout << M << endl;
  for (int i=0;i<ans.size();i++){
    if (i>0) cout << " ";
    cout << ans[i];
  } 
  cout << endl;


  // cout << fixed << setprecision(10);
  
  return 0;
}
