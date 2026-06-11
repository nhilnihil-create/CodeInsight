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

// ランレングス圧縮(Run Length Encoding)
vector<pair<char,int>> RLE(string S){
  vector<pair<char,int>> p;
  int N = S.size();
  for (int i=0;i<N;i++) {
    if (S[i]==S[i+1]){
      int cnt = 1;
      char c = S[i];
      while (i+1<N && S[i]==S[i+1]) {
        i++;
        cnt++;
      }
      p.push_back({c,cnt});
    }
    else p.push_back({S[i],1});
  }

  return p;
}

int main(){
  string S; cin >> S;
  int N = S.size();
  int a[N] = {};

  auto p = RLE(S);
  int cumsum = 0;
  for (int j=0;j<p.size();j+=2){
    int r = p[j].second;
    int l = p[j+1].second;
    a[cumsum+p[j].second-1] += r/2 + l/2 + r%2;
    a[cumsum+p[j].second] += r/2 + l/2 + l%2;
    cumsum += p[j].second + p[j+1].second;
  }
  rep(i,N) {
    if (i>0) cout << " ";
    cout << a[i];
  }
  cout << endl;  

  // cout << fixed << setprecision(10);
  
  return 0;
}
