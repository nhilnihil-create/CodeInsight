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
  int N, M; cin >> N >> M;
  int A;
  priority_queue<int> q;
  rep(i,N) {
    cin >> A;
    q.push(A);
  }
  
  rep(i,M){
    int a = q.top(); q.pop();
    q.push(a/2);
  }

  ll retval = 0;
  rep(i,N) {
    int a = q.top(); q.pop();
    retval += a;
  }
  cout << retval << endl;


  // cout << fixed << setprecision(10);
  
  return 0;
}
