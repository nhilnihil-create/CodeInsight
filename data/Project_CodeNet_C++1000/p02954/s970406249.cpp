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
  string S; cin >> S;
  int N = S.size();
  int a[N] = {};

  vector<pii> p;
  rep(i,N) {
    if (S[i]==S[i+1]){
      int cnt = 1;
      int s = i;
      while (i+1<N && S[i]==S[i+1]) {
        i++;
        cnt++;
      }
      p.push_back({s,cnt});
    }
    else p.push_back({i,1});
  }
  for (int j=0;j<p.size();j+=2){
    int l = p[j+1].second;
    int r = p[j].second;
    a[p[j+1].first-1] = r/2 + l/2 + r%2;
    a[p[j+1].first] = r/2 + l/2 + l%2;
  }
  rep(i,N){
    if (i>0) cout << " ";
    cout << a[i];
  }
  cout << endl;
  

  // cout << fixed << setprecision(10);
  
  return 0;
}
