#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int sum[200010];

void calc(int n){
  for(int i=1;i*i<=n;i++){
    if(n%i==0){
      sum[i]++;
      if(i*i==n) continue;
      sum[n/i]++;
    }
  }
}
int main(){
  int N; cin >> N;
  int A[N+1];
  for(int i=1;i<=N;i++){
    cin >> A[i];
  }
  int ans[N+1];
  memset(ans,0,sizeof(ans));  
  memset(sum,0,sizeof(sum));
  vector<int> s;
  int cnt = 0;
  for(int i=N;i>=1;i--){
    if(sum[i]%2!=A[i]){
      ans[i] = 1;
      cnt++;
      s.push_back(i);
      calc(i);
    }
  }
  cout << cnt << endl;
  reverse(s.begin(),s.end());
  for(auto x : s){
    cout << x << " ";
  }
}
