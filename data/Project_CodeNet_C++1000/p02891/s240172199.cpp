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
  string s; cin >> s;
  int K; cin >> K;
  int N = s.size();

  ll cnt_1 = 0, cnt_2 = 0,cnt_3 = 0;
  rep(i,N){
    if (i+1<N && s[i]==s[i+1]){
      cnt_1++;
      i++;
    }
  }
  s += s;
  rep(i,s.size()){
    if (i+1<2*N && s[i]==s[i+1]){
      cnt_2++;
      i++;
    }
  }
  s += s;
  rep(i,s.size()){
    if (i+1<3*N && s[i]==s[i+1]){
      cnt_3++;
      i++;
    }
  }
  if (K%2) cout << cnt_1 + (cnt_3-cnt_1)*(K/2) << endl;
  else cout << cnt_2 + (cnt_3-cnt_1)*(K/2-1) << endl;




  
  
  // cout << fixed << setprecision(10);
  
  return 0;
}
